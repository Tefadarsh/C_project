

#define MAX_SIZE 10

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;
typedef enum {False, True} bool;

typedef struct{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
}student;

struct Node{
    student data;
    struct Node* pRight;
    struct Node* pLeft;
}*pHead,*pEnd;


uint8 start;
uint8 checker;
uint32 id;
uint32 List[10];
uint8 count;


struct Node* createNode();
uint8 SDB_GetUsedSize();
bool SDB_IsFull();
bool SDB_AddEntry();
void SDB_DeletEntry(uint32);
bool SDB_ReadEntry(uint32);
bool SDB_IsIdExist(uint32);
void SDB_GetList(uint8*,uint32*);
//void SDB_APP();
//void SDB_action (uint8);

