// Su nombre aqui

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************


// This class is able to store either a symbol or a float.
class token {
public:
  char type;
  union {
    char symbol;
    float value;
  };
  token(char c) {type = 's'; symbol = c;}
  token(float val) {type = 'v'; value = val;}
};


// Given a vector of tokens that represents a valid postfix expression
// returns the result of the evaluation

float evalOp(const vector<token> &V){
  stack<float> S;
  for (auto it: V) {
    if (it.type == 'v') S.push(it.value);
    else {
      float a = S.top(); S.pop();
      float b = S.top(); S.pop();
      if (it.symbol == '+') S.push(a+b);
      else  S.push(a*b);     
    }
  }
  return(S.top());
}

int main() {

  // creamos un vector con la expresion "1.5 3.0 +"
  vector<token> V {token((float)(1.5)), token((float)3.0), token((char)('+'))};

  expect(abs(evalOp(V) - 4.5)  < 0.0001);

  // creamos un vector con la expresion "1.5 3.0 + 2.0 *"
  vector<token> W { token((float)(1.5)), token((float)3.0), token((char)('+')), 
                    token((float)2.0), token((char)('*'))};

  expect(abs(evalOp(W) - 9.0)  < 0.0001);

  // creamos un vector con la expresion "1.5 3.0 2.0 + *"
  vector<token> Y { token((float)(1.5)), token((float)3.0), 
                    token((float)2.0),  token((char)('+')), token((char)('*'))};

  expect( abs(evalOp(Y) - 7.5)  < 0.0001 );

  assertionReport();
}
