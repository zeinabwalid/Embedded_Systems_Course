#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef signed int int32_t;

typedef struct data {
        int ID;
        char name[8];
        char phone[11];
        char email[50];
    }subj;


int32_t main(void);
void access(char*);
void read(void);
void delete_fun(void);
void add_fun (subj );
void modify_fun(void);
void find_byname_fun(void);
void find_byphone_fun(void);
#endif // HEADER_H_INCLUDED
