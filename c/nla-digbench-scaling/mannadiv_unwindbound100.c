/* 
 Division algorithm from
 "Z. Manna, Mathematical Theory of Computation, McGraw-Hill, 1974"
 return x1 // x2
*/

extern void abort(void);
void reach_error(){}
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        {reach_error();}
    }
    return;
}
int counter = 0;
int main() {
    int x1, x2;
    int y1, y2, y3;
    x1 = __VERIFIER_nondet_int();
    x2 = __VERIFIER_nondet_int();

    assume_abort_if_not(x1 >= 0);
    assume_abort_if_not(x2 != 0);

    y1 = 0;
    y2 = 0;
    y3 = x1;

    while (counter++<100) {
        __VERIFIER_assert(y1*x2 + y2 + y3 == x1);

        if (!(y3 != 0)) break;

        if (y2 + 1 == x2) {
            y1 = y1 + 1;
            y2 = 0;
            y3 = y3 - 1;
        } else {
            y2 = y2 + 1;
            y3 = y3 - 1;
        }
    }
    __VERIFIER_assert(y1*x2 + y2 == x1);
    return 0;
}
