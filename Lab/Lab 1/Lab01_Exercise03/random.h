#define RAND_SEED 123
#define RANDOM_A 1103515245 
#define RANDOM_C 12345

// extern functions need to be realised in main files
extern void init_random();
extern unsigned short random_ushort();
// Ex 2.5 (1/2), A further prototype is added for our new random function
extern unsigned int random_uint();

