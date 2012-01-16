/**
* Reference counting helpers.
*/

#ifndef SI_REF_H
#define SI_REF_H

/** A Count keeps a reference count */
typedef int32_t SiCount;

/** a Ref keeps a count and a pointer wrapped. */
struct  SiRef_;
typedef struct SiRef_ SiRef;

/** A runtime is the runtime support for Si's reference counting
and other. Every thread should have it's own runtime. */
struct  SiRuntime_;
typedef struct SiRuntime_ SiRuntime;

#define SI_REFCOUNT_NAME    si_count_
#define SI_REFCOUNT_TYPE    SiCount
#define SI_REFCOUNT_OF(PTR) ((PTR)->SI_REFCOUNT_NAME)
#define SI_REFCOUNT         SI_REFCOUNT_TYPE SI_REFCOUNT_NAME
#define SI_USE(PTR) SiRefUse(PTR, &(SI_REFCOUNT_OF(PTR)));

typedef void (SiDestructor(void *));

struct SiRef_ {
  void    * ptr;
  SI_REFCOUNT;
};

/** Gets the active runtime. */
SiRuntime * siruntime_now();
/** Sets the active runtime. */
SiRuntime * siruntime_now_(SiRuntime * runtime);
/** Increases the reference count */

struct SiRefNode_;
typedef struct SiRefNode_ SiRefNode;

struct SiRefNode_ {
  SiRef         * ref;  
  SiRefNode     * next;  
  SiDestructor  * free;
};

struct SiRuntime_ {
  SiRefNode * nodes;
}; 






#endif // SI_REF_H



