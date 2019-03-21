#ifndef KMUVCL_GRAPHICS_MAT_HPP
#define KMUVCL_GRAPHICS_MAT_HPP

#include <iostream>
#include <cstring>
#include <cstdarg>

namespace kmuvcl {
  namespace math {

    template <unsigned int M, unsigned int N, typename T>
    class mat
    {
    public:
      mat()
      {
        set_to_zero();
      }

      mat(const T elem)
      {
        std::fill(val, val + M*N, elem);
      }

      T& operator()(unsigned int r, unsigned int c)
      {
        return  val[r + c * N];
      }

      const T& operator()(unsigned int r, unsigned int c) const
      {
        return  val[r + c * N];   
      }

      // type casting operators
      operator const T* () const
      {
        return  val;
      }

      operator T* ()
      {
        return  val;
      }

      void set_to_zero()
      {
	for(int i = 0; i < M * N; i++)
	  val[i] = 0;
      }

      void get_ith_column(unsigned int i, vec<M, T>& col) const
      {
	for(int j = 0; j < M; j++)
	  col[j] = val[i * M + j];
      }

      void set_ith_column(unsigned int i, const vec<M, T>& col)
      {
	for(int j = 0; j < M; j++)
	  col[j] = val[i * M + j];
      }

      void get_ith_row(unsigned int i, vec<N, T>& row) const
      {
	for(int j = 0; j < N; j++)
	  row[j] = val[N * j + i];
      }

      void set_ith_row(unsigned int i, const vec<N, T>& row)
      {
	for(int j = 0; j < N; j++)
	  row[j] = val[N * j + i];
      }

      mat<N, M, T> transpose() const
      {
        mat<N, M, T>  trans;

	for(int i = 0; i < N; i++)
	  for(int j = 0; j < M; j++)
	    trans(i, j) = val[i * N + j];

        return  trans;
      }

    protected:
      T val[M*N];   // column major
    };

    typedef mat<3, 3, float>    mat3x3f;
    typedef mat<3, 3, double>   mat3x3d;

    typedef mat<4, 4, float>    mat4x4f;
    typedef mat<4, 4, double>   mat4x4d;

  } // math
} // kmuvcl

#include "operator.hpp"

#endif // #ifndef KMUVCL_GRAPHICS_MAT_HPP
