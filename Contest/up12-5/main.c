#include <iostream>
namespace numbers {
        class complex_stack {
            complex *array{nullptr};
            size_t size_{};
            size_t max_size{8};
            public:
            complex_stack(size_t max = 8, size_t size = 0) : size_{size}, max_size{max}
            {
                array = static_cast<complex*>(operator new[] (max_size * sizeof(complex)));
            }
            complex_stack(complex_stack const & cs) : size_{cs.size_}, max_size{cs.max_size} {
                array = static_cast<complex*>(operator new[] (max_size * sizeof(complex)));
                for (size_t i = 0; i < size_; ++i) {
                    new (array + i) complex(cs.array[i]);
                }
            }
            ~complex_stack() {
                for (size_t i = 0; i < size_; ++i) {
                    array[i].~complex();
                }
                operator delete [] (array);
            }
            size_t size() const {
                return size_;
	
            }
            complex_stack & operator=(complex_stack& cs) {
                if (this != &cs) {
                    if (cs.array != nullptr) {
                        this->~complex_stack();
                        size_= cs.size_;
                        max_size = cs.max_size;
                        array = static_cast<complex*>(operator new[] (max_size * sizeof(complex)));
                        for (size_t i = 0; i < size_; i++) {
                            new (array + i) complex(cs[i]);
                        }
                    }
                }
                return *this;
            }
            complex operator[](size_t i) const {
                return array[i];
            }
            complex operator+() const {
                return array[size_ - 1];
            }
            complex_stack operator~() const {
                complex_stack tmp(*this);
                tmp[--tmp.size_].~complex();
                return tmp;
            }
            complex_stack operator<<(complex z) const{
                size_t new_size = this->max_size;
                if (this->size_ == this->max_size) {
                    new_size *= 2;
                }
                complex_stack tmp(new_size, this->size_ + 1);
                for (size_t i = 0; i < this->size_; ++i) {
                    new (tmp.array + i) complex(array[i]);
                }
                new (tmp.array + this->size_) complex(z);
                return tmp;
            }
        };
}
