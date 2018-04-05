#include <iostream>
#include <new>

template<typename X> using owner = X;

template<typename T>
class Vector {
  public:
    Vector(int sz) : sz(sz) {
      elem = new (sz * sizeof(T)) T;
    }

    Vector(Vector&& r) : elem(r.elem), sz(r.sz) {
      r.elem = nullptr;
      r.sz = 0;
    }

    ~Vector() {
      delete elem;
    }

    int get_size() {
      return sz;
    }

    T* get_elem() {
      return elem;
    }

  private:
    owner<T*> elem;
    int sz;
};

int main(int argc, char** argv) {
  Vector<int*> i = Vector<int*>(1);
  Vector<int*> j(i);

  printf("%d%d\n",i.get_size(), j.get_size());

  return 0;
}
