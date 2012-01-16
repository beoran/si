#include "si.h"
#include "si_ref.h"


SiRuntime * runtime = NULL;

SiRuntime * siruntime_now() {
  return runtime;
}

SiRuntime * siruntime_now_(SiRuntime * runtime) {
  return runtime;
}

SiRuntime * siruntime_init(SiRuntime * self) {
  if(!self) return NULL;
  self->next = NULL;
  return self;
}

SiRuntime * siruntime_autofree(SiRuntime * runtime,
                                SiRef * ref, SiDestructor * dest ) {
  SiRefNode * node = SI_ALLOCATE(SiRefNode);
  node->ref  = ref;
  node->free = dest ? dest : si_free;
  if(runtime->next) {
    node->next = runtime.next;
  }  
  if(runtime->next) = node;
  return self;
}

SiRuntime * siruntime_purge(SiRuntime * runtime, SiRef * ref) {


SiRef * siref_autofree(SiRef * ref, SiDestructor * dest) {
  SiRuntime runtime = siruntime_now();
  siruntime_autofree(runtime, ref, dest);
  return ref;
}














