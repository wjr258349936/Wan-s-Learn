#include "LinkList.h"
#include "joseph.h"
#include "DoubleLoopLink.h"

void test01(){
    LinkLoop link_loop;
    initLinkLoop(&link_loop);

    for(int i = 0;i < 10;++i){
        linkLoopInsertHeader(&link_loop,i+100);
    }
    showLinkLoop(&link_loop);
    linkLoopDeleteEle(&link_loop,104);
    showLinkLoop(&link_loop);
    linkLoopDeleteAll(&link_loop);
}

void test02(){
    JosephHeader game1;
    initJosephGame(&game1,10);
    showJosephGame(&game1);
    startJosephGame(&game1,3);
}

void test03(){
    DuLoopLink loop_link;
    initDuLoopLink(&loop_link);
    for(int i=1;i<=10;++i){
        //insertDuLoopLinkHeader(&loop_link,i+100);
        insertDuLoopLinkRear(&loop_link,i+100);
    }
    showDuLoopLink(&loop_link);
    deleteValueDuLoopLink(&loop_link,103);
    showDuLoopLink(&loop_link);
    deleteAllLinkLoop(&loop_link);
}
int main(){
    //test01();
    test02();
//    test03();
}
