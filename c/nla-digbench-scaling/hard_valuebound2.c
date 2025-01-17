/*
  hardware integer division program, by Manna
  returns q==A//B
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

int main() {
    int A, B;
    int r, d, p, q;
    A = __VERIFIER_nondet_int();
    assume_abort_if_not(A>0 && A<=2);
    B = __VERIFIER_nondet_int();
    assume_abort_if_not(B>0 && B<=2);
    assume_abort_if_not(B >= 1);

    r = A;
    d = B;
    p = 1;
    q = 0;

    while (1) {
        __VERIFIER_assert(q == 0);
        __VERIFIER_assert(r == A);
        __VERIFIER_assert(d == B * p);
        if (!(r >= d)) break;

        d = 2 * d;
        p = 2 * p;
    }

    while (1) {
        __VERIFIER_assert(A == q*B + r);
        __VERIFIER_assert(d == B*p);

        if (!(p != 1)) break;

        d = d / 2;
        p = p / 2;
        if (r >= d) {
            r = r - d;
            q = q + p;
        }
    }

    __VERIFIER_assert(A == d*q + r);
    __VERIFIER_assert(B == d);    
    return 0;
}
