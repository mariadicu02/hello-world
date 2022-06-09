typedef struct {
  unsigned int key;
  float value;
}El_t;//structura element

typedef struct {
  El_t *array;
  int size;
}KVS_t;//structura kvs


KVS_t* adauga(KVS_t*, El_t);
void printKVS(KVS_t*);
int cauta(KVS_t*, unsigned);
