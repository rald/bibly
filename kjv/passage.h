#ifndef PASSAGE_H
#define PASSAGE_H

#include <stdlib.h>
#include <string.h>

typedef struct Passage Passage;

struct Passage {
  char *bname;
  size_t bnum;
  size_t cnum;
  size_t vnum;
  char *text;
};



Passage *Passage_New(char *bname,size_t bnum,size_t cnum,size_t vnum,char *text);

void Passage_Append(Passage ***passages,size_t *npassages,Passage *passage);

void Passages_Print(Passage **passages,size_t npassages) ;

void Passage_Free(Passage **passage);

void Passage_Append(Passage ***passages,size_t *npassages,Passage *passage);

void Passage_Print(Passage *passage);

void Passages_Print(Passage **passages,size_t npassages);



#ifdef PASSAGE_IMPLEMENTATION

Passage *Passage_New(char *bname,size_t bnum,size_t cnum,size_t vnum,char *text) {
  Passage *passage=malloc(sizeof(*passage));
  if(passage) {
    passage->bname=strdup(bname);
    passage->bnum=bnum;
    passage->cnum=cnum;
    passage->vnum=vnum;
    passage->text=strdup(text);
  }
  return passage;
}



void Passage_Free(Passage **passage) {
  free((*passage)->bname);
  (*passage)->bname=NULL;
  free((*passage)->text);
  (*passage)->text=NULL;
  free(*passage);
  *passage=NULL;
}



void Passages_Free(Passage ***passages,size_t *npassages) {
  size_t i;
  for(i=0;i<*npassages;i++) {
    Passage_Free(&(*passages)[i]);
  }
  free(*passages);
  *passages=NULL;
}



void Passage_Append(Passage ***passages,size_t *npassages,Passage *passage) {
  (*passages)=realloc(*passages,sizeof(**passages)*((*npassages)+1));
  (*passages)[(*npassages)++]=passage;
}



void Passage_Print(Passage *passage) {
  printf("%s %zu:%zu -> %s\n",
    passage->bname,
    passage->cnum,
    passage->vnum,
    passage->text
  );
}


void Passages_Print(Passage **passages,size_t npassages) {
  size_t i;
  for(i=0;i<npassages;i++) {
    Passage_Print(passages[i]);
  }
}



#endif /* PASSAGE_IMPLEMENTATION */



#endif /* PASSAGE_H */
