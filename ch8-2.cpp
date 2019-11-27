#include <algorithm>

template <class In, class In2>
bool equal(In beg, In end, In2 b2) {
  while (beg != end)
    if (*beg++!=b2++) 
      return false;
  return true;
}

template<class In, class T>
In find(In beg, In end, const T& t) {
  while (beg != end && *beg++!=t)
  return beg;
}

template<class In, class Out>
Out copy(In beg, In end, Out dst) {
  while (beg != end) 
    *dst++=*beg++;
  return dst;
}

template<class In, class Out, class Pred>
Out remove_copy_if(In beg, In end, Out dst, Pred p) {
  while (beg != end) 
    if (p(dst))
      dst++;
    else 
    *dst++=*beg++;
  return dst;
}

template<class In, class Out, class Func>
Out transform(In beg, In end, Out dst, Func fnc)
  while (beg != end)
    *dst++ = fnc(*beg++)
  return dst;

template<class In, class T>
T accumulate(In beg, In end, const T& t) {
  T tmp = t;
  while (beg != end)
    tmp += *beg++;
  return tmp;
}

template<class In>
In search(In beg, In end, In b2, In e2) {
  while (beg != end)
    if (*beg++ == b2++)
}


