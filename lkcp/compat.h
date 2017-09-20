#include "Python.h"

typedef void (*capsule_dest)(PyObject *);
typedef void (*cobj_dest)(void *);

#if PY_MAJOR_VERSION != 2
    #error "need python 2.*"
#elif PY_MINOR_VERSION > 6
    #define CAP_NEW PyCapsule_New
    #define DEST_FUNC_TYPE capsule_dest
    #define CAP_GET_POINTER PyCapsule_GetPointer
#else
    #define CAP_NEW(a,b,c) PyCObject_FromVoidPtr(a,c)
    #define DEST_FUNC_TYPE cobj_dest
    #define CAP_GET_POINTER(a,b) PyCObject_AsVoidPtr(a)
#endif

PyObject* make_capsule(void *p, const char *name, capsule_dest dest) {
    return CAP_NEW(p, name, (DEST_FUNC_TYPE)dest);
}
void* get_pointer(PyObject *cap, const char *name) {
    return CAP_GET_POINTER(cap, name);
}
