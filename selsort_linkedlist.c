

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/////////////////////////////////////////////
struct NODE {
  int val;
  struct NODE *next;
};

/////////////////////////////////////////////
void freelist(struct NODE *head)
{
  struct NODE *next;
  while ( head ) {
    next = head->next;
    free(head);
    head = next;
  }
}

/////////////////////////////////////////////
void printlist(struct NODE *head)
{
  while ( head ) {
    fprintf(stdout, "%d\n", head->val);
    head = head->next;
  }
}

/////////////////////////////////////////////
// List SELECTION SORT
struct NODE* selectionsort_list(struct NODE *head)
{
struct NODE *now;
struct NODE *cur;
int tmp;
	cur=head;
	while ( cur ) {
		
		now = head;
		while(now){
		if (cur->val>now->val)
		{
			tmp = cur->val;
			cur->val = now->val;
			now->val = tmp;
		}
		now = now->next;
		}

		cur=cur->next;	
	}
return head;
}

/////////////////////////////////////////////

int main()
{
  int i, N;
  int val;
  struct NODE *head, *tail, *cur;

  fprintf(stderr, "How many numbers? ");
  fscanf(stdin, "%d", &N);

  head = tail = NULL;
  for (i=0; i<N; i++) {
    if ( fscanf(stdin, "%d", &val) != 1 ) {
      fprintf(stderr, "cannot read integer from standard input.\n");
      freelist(head);
      exit(0);
    }
    else {
      cur = (struct NODE*) malloc(sizeof(struct NODE));
      cur->val = val;
      cur->next = NULL;
      if ( !head ) head = tail = cur;
      else {
	tail->next = cur;
	tail = cur;
      }
    }
  }
  head = selectionsort_list(head);

  printlist(head);

  // free memory
  freelist(head);

  return 0;
}
