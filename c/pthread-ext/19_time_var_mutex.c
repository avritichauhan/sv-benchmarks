extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

#include <pthread.h>

#define assume(e) assume_abort_if_not(e)
#undef assert
#define assert(e) { if(!(e)) { ERROR: {reach_error();abort();}(void)0; } }

void __VERIFIER_atomic_acquire(int * m)
{
	assume(*m==0);
	*m = 1;
}

void __VERIFIER_atomic_release(int * m)
{
	assume(*m==1);
	*m = 0;
}

int block;
int busy; // boolean flag indicating whether the block has be an allocated to an inode
int inode;
int m_inode=0; // protects the inode
int m_busy=0; // protects the busy flag

void * thr1(void* arg)
{
  __VERIFIER_atomic_acquire(&m_inode);
  if(inode == 0){
    __VERIFIER_atomic_acquire(&m_busy);
    busy = 1;
    __VERIFIER_atomic_release(&m_busy);
    inode = 1;
  }
  block = 1;
  assert(block == 1);
  __VERIFIER_atomic_release(&m_inode);

  return 0;
}

void * thr2(void* arg)
{
  __VERIFIER_atomic_acquire(&m_busy);
  if(busy == 0){
    block = 0;
    assert(block == 0);
  }
  __VERIFIER_atomic_release(&m_busy);

  return 0;
}

int main()
{
  pthread_t t;

  pthread_create(&t, 0, thr1, 0);
  thr2(0);

  return 0;
}

