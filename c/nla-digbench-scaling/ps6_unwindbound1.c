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
    int k, y, x, c;
    k = __VERIFIER_nondet_int();

    y = 0;
    x = 0;
    c = 0;

    while (counter++<1) {
        __VERIFIER_assert(-2*y*y*y*y*y*y - 6 * y*y*y*y*y - 5 * y*y*y*y + y*y + 12*x == 0);

        if (!(c < k))
            break;

        c = c + 1;
        y = y + 1;
        x = y * y * y * y * y + x;
    }
    
    __VERIFIER_assert(-2*y*y*y*y*y*y - 6 * y*y*y*y*y - 5 * y*y*y*y + y*y + 12*x == 0);
    __VERIFIER_assert(k*y == y*y);		      
    return 0;
}
