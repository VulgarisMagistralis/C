#ifndef _DATO_INCLUDED
#define _DATO_INCLUDED
#define MAX_NAME 21
#define REG 10
typedef struct item* Item;
typedef char *Key;
Item ITEMscan();
void ITEMshow(Item data);
int ITEMcheckvoid(Item data);
Item ITEMsetvoid();
Key KEYscan();
int KEYcompare(Key k1, Key k2);
Item ITEMset(char*,char*,int,int);
Key KEYget(Item data);
#endif
