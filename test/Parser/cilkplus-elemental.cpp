// RUN: %clang_cc1 -fcilkplus -std=c++11 -fsyntax-only -verify -Wall %s

[[vector(vectorlengthfor(1))]] // expected-warning {{unknown attribute 'vectorlengthfor' - ignored}}
int test_vectorlengthfor_11(int x);

__attribute((vector(vectorlengthfor(2)))) // expected-warning {{unknown attribute 'vectorlengthfor' - ignored}}
int test_vectorlengthfor_12(int x);

__declspec(vector(vectorlengthfor(2))) // expected-warning {{unknown attribute 'vectorlengthfor' - ignored}}
int test_vectorlengthfor_13(int x);

class X {
  __attribute__((vector(linear(this)))) // OK
  __attribute__((vector(uniform(this)))) // OK
  __attribute__((vector(linear(goto)))) // expected-error {{expected identifier or this}}
  __attribute__((vector(uniform(goto)))) // expected-error {{expected identifier or this}}
  void member();
};

__declspec(vector)               // OK
__declspec(vector())             // OK
__declspec(vector noinline)      // OK
__declspec(noinline vector)      // OK
__attribute__((vector))          // OK
__attribute__((vector()))        // OK
__attribute__((vector noinline)) // OK
__attribute__((noinline vector)) // OK
void test_vector();
