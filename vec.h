#include <cstddef>
#include <memory>

template <class T> class Vec {
  public:
    // various typedefs needed
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    
    // ctors
    Vec() { create(); } // default ctor
    Vec(const Vec& vec) { create(vec.begin(), vec.end()); } // copy ctor 
    explicit Vec(std::size_t n, const T& val = T()) { create(n, val); }

    // overloading the = operator
    Vec& operator=(const Vec&);
    
    size_type size() const { return limit - data; }

    // overloads the []. the const is needed in case the object is const
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // iterators. once again, the functions return const_iterators and are 
    // themselves const in case the Vec is const
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return limit; } 
    const_iterator end() const { return limit; } 

    void push_back(const T& t) {
      if (avail == limit) 
        grow();
      unchecked_append(t);
    }

    void clear() { 
      if (data) {
        iterator it = avail;
        while (it != data)
          alloc.destroy(it--);
      }
      data = limit = avail = 0;
    }
    // destructor
    ~Vec() { uncreate(); }

  private:
    T* data;
    T* limit;
    T* avail;
    std::allocator<T> alloc;

    void create() {
      data = avail = limit = 0;
    }
    void create(size_type n, const T& val) {
      data = alloc.allocate(n);
      limit = avail = data + n;
      uninitialized_fill(data, limit, val);
    }
    void create(const_iterator i, const_iterator j) {
      data = alloc.allocate(j - i);
      limit = avail = uninitialized_copy(i, j, data);
    }
    void uncreate() {
      if (data) {
        iterator it = avail;
        while (it != data) {
          alloc.destroy(it--);
        }
        alloc.deallocate(data, limit - data);
      }
      data = limit = avail = 0;
    }
    void grow() {
      size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
      iterator new_data = alloc.allocate(new_size);
      iterator new_avail = uninitialized_copy(data, avail, new_data);

      uncreate();
      data = new_data; 
      avail = new_avail; 
      limit = data + new_size;

    }
    void unchecked_append(const T& val) {
      alloc.construct(avail++, val);
    }
};
