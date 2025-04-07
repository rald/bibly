#define _GNU_SOURCE

#include "ezxml/ezxml.h"



#define PASSAGE_IMPLEMENTATION
#include "passage.h"

#define INFO_IMPLEMENTATION
#include "info.h"

#define UTIL_IMPLEMENTATION
#include "util.h"




int main(void) {

  Passage **passages=NULL;
  size_t npassages=0;

  char *bname=NULL;
  size_t bnum=0;
  size_t cnum=0,vnum=0;
  char *text=NULL;

  size_t i,j;

  ezxml_t bible = ezxml_parse_file("adb.xml"),book,chap,vers;

  for (book = ezxml_child(bible, "BIBLEBOOK"); book; book = book->next) {
    for (chap = ezxml_child(book, "CHAPTER"); chap; chap = chap->next) {
      for (vers = ezxml_child(chap, "VERS"); vers; vers = vers->next) {
        bname =strdup(ezxml_attr(book,"bname"));
        bnum = atoi(ezxml_attr(book,"bnumber"));
        cnum = atoi(ezxml_attr(chap,"cnumber"));
        vnum = atoi(ezxml_attr(vers,"vnumber"));
        text = strdup(ezxml_txt(vers));

        Passage_Append(&passages,&npassages,Passage_New(bname,bnum,cnum,vnum,text));
        free(bname);
        bname=NULL;

        free(text);
        text=NULL;

      }
    }
  }
  ezxml_free(book);

  for(i=0;i<npassages;i++) {
    printf("%s|%zu|%zu|%s\n",
      passages[i]->bname,
      passages[i]->cnum,
      passages[i]->vnum,
      passages[i]->text
    );
  }

  Passages_Free(&passages,&npassages);

  return 0;
}



