#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void in_order_tree_walk(struct Node start);

struct Page
{
    unsigned int value;
    struct Page *parent;
    struct Page *lSon;
    struct Page *rSon;
};


struct Node
{
    string value;
    struct Node *parent;
    struct Node *lSon;
    struct Node *rSon;
    struct Page *rootP;
};
struct Node *rootL;



//          SZUKANIE            //

struct Page *naj_lewoP(struct Page *start) {
    while (start->lSon != NULL)
        start = start->lSon;
    return start;
}

struct Node *naj_lewo(struct Node *start)
{
    while (start->lSon != NULL)
        start = start->lSon;
    return start;
}


struct Node *searchN(struct Node *start, string value)
{
    if ((start == NULL) || (start->value == value)) return start;
    else if (value < start->value && start->lSon != NULL) return searchN(start->lSon, value);
    else if (value > start->value && start->rSon != NULL) return searchN(start->rSon, value);
    return NULL;
}

struct Page *searchP(struct Page *start, unsigned int value)
{
    if ((start == NULL) || (start->value == value)) return start;
    else if (value < start->value && start->lSon != NULL) return searchP(start->lSon, value);
    else if (value > start->value && start->rSon != NULL) return searchP(start->rSon, value);
    return NULL;
}



//          DODAWANIE       //

int dodawanieP(struct Node *node, struct Page *start)
{
    struct Page *y = NULL;
    struct Page *x = node->rootP;

    while (x != NULL)
    {
        y = x;

        if (start->value < x->value)
        {
            x = x->lSon;
        }
        else
        {
            x = x->rSon;
        }
    }

    start->parent = y;

    if (y == NULL)
    {
        node->rootP = start;
    }
    else
    {
        if (start->value < y->value)
        {
            y->lSon = start;
        }
        else
        {
            y->rSon = start;
        }
    }
    return 0;
}


void dodawaniePfor(unsigned int x, struct Node *node)
{
    unsigned int licz = 0;
    for (unsigned int i = 0; i<x; i++)
    {
        cin >> licz;
        struct Page *ppage;
        ppage = searchP(node->rootP, licz);
        if (ppage == false) {
            struct Page *page = new Page;
            page->value = licz;
            page->lSon = NULL;
            page->rSon = NULL;
            page->parent = NULL;
            dodawanieP(node, page);
        }
    }


}



int dodawanieNEW(struct Node *node)
{
    struct Node *y = NULL;
    struct Node *x = rootL;

    while (x != NULL)
    {
        y = x;

        if (node->value < x->value)
        {
            x = x->lSon;
        }
        else
        {
            x = x->rSon;
        }
    }

    node->parent = y;

    if (y == NULL)
    {
        rootL = node;
    }
    else
    {
        if (node->value < y->value)
        {
            y->lSon = node;
        }
        else
        {
            y->rSon = node;
        }
    }
    return 0;
}





//          KASOWANIE       //

void deleNode(struct Node *start)
{
    if (start != NULL) {                                 //zmiana
        if ((start->lSon == NULL) && (start->rSon == NULL))
        {
            if (start==rootL)
            {
                rootL = NULL;
                start=NULL;                             //zmienione
            }
            else if (start->parent->lSon == start)
            {
                if(rootL==start->parent){
                    start->parent->lSon=NULL;
                    rootL->lSon=NULL;
                }
                else
                {
                start->parent->lSon=NULL;
                start->parent=NULL;                     //zmienione
                }
            }
            else if (start->parent->rSon == start)
            {
                if(rootL==start->parent){
                    start->parent->rSon=NULL;
                    rootL->rSon=NULL;
                }
                else
                {
                start->parent->rSon=NULL;
                start->parent=NULL;                     //zmienione
                }
            }

            //delete start;
        }
        else if (start->lSon == NULL || start->rSon == NULL)
        {
            if (start->lSon == NULL)
            {
                if (start==rootL)
                {
                    rootL = start->rSon;
                    start->parent=NULL;                     //zmienione
                }
                else if (start->parent->lSon == start)
                {
                    start->parent->lSon = start->rSon;
                    start->rSon->parent=start->parent;                  //zmiana
                }
                else if (start->parent->rSon==start)
                {
                    start->parent->rSon = start->rSon;
                    start->rSon->parent=start->parent;
                }
            }
            else
            {
                if (rootL==start)
                {
                    rootL = start->lSon;
                    start->parent=NULL;                     //zmieonione
                }
                else if (start->parent->lSon == start)
                {
                    start->parent->lSon=start->lSon;
                    start->lSon->parent=start->parent;
                }
                else if (start->parent->rSon == start)
                {
                    start->parent->rSon=start->lSon;
                    start->lSon->parent=start->parent;
                }
            }
            //delete start;
        }
        else if (start->lSon != NULL && start->rSon != NULL)
        {
            struct Node *tempP;
            tempP = naj_lewo(start->rSon);
            if (tempP != NULL) {
                start->value = tempP->value;
                start->rootP = tempP->rootP;
                /////////////////////////////////////////////////////
                if (tempP->parent == start)
                {
                    if (start == rootL)
                    {
                        if (tempP->rSon != NULL)
                        {
                            tempP->rSon->parent = rootL;
                            rootL->rSon = tempP->rSon;
                        }
                        else if (tempP->rSon == NULL)
                        {
                            rootL->rSon = NULL;
                        }
                    }


                    else if (tempP->rSon != NULL)
                    {
                        tempP->parent->rSon=tempP->rSon;
                        tempP->rSon->parent=tempP->parent;              /// uwagaaa
                    }

                    else if (tempP->rSon == NULL)
                    {
                        start->rSon = NULL;
                        tempP=NULL;                     //zmienione
                    }
                }


                else if (tempP->rSon == NULL)
                {
                    tempP->parent->lSon = NULL;
                    tempP=NULL;                 //zmiana
                }


                else if (tempP->rSon != NULL)
                {
                    tempP->rSon->parent = tempP->parent;
                    tempP->parent->lSon = tempP->rSon;
                }
                /////////////////////////////////////////////////////////////////
            }
        }

    }
}



void delePage(struct Node *startN, struct Page *start)
{
    if (startN != NULL && start!=NULL && startN->rootP!=NULL) {
        if (start != NULL) {
            if ((start->lSon == NULL) && (start->rSon == NULL))
            {
                if (start->parent == NULL)
                {
                    if(startN->rootP!=NULL)
                    {
                        startN->rootP=NULL;
                        start=NULL;
                    }
                }
                else if (start->parent->lSon == start)
                {
                    start->parent->lSon = NULL;

                }
                else if (start->parent->rSon == start)
                {
                    start->parent->rSon = NULL;
                }
                ////delete start;
            }
            else if ((start->lSon == NULL) || (start->rSon == NULL))
            {
                if (start->lSon == NULL)
                {
                    if (start->parent == NULL)
                    {
                        startN->rootP = start->rSon;
                        startN->rootP->parent = NULL;
                    }
                    else if (start->parent->lSon == start)
                    {
                        start->parent->lSon = start->rSon;
                        start->parent->lSon->parent = start->parent;                  // new parent
                    }
                    else if (start->parent->rSon == start)
                    {
                        start->parent->rSon = start->rSon;                     // new parent
                        start->rSon->parent=start->parent;
                    }
                }
                else
                {
                    if (start->parent == NULL)
                    {
                        startN->rootP = start->lSon;
                        startN->rootP->parent = NULL;
                    }
                    else if (start->parent->lSon == start)
                    {
                        start->parent->lSon = start->lSon;
                        start->lSon->parent=start->parent;
                    }
                    else if (start->parent->rSon == start)
                    {
                        start->parent->rSon = start->lSon;
                        start->parent->rSon->parent = start->parent;
                    }
                }
                //delete start;
            }
            else if ((start->lSon != NULL) && (start->rSon != NULL))
            {

                struct Page *tempP;
                if (start->rSon != NULL)
                {
                    tempP = naj_lewoP(start->rSon);
                    if (tempP != NULL) {
                        start->value = tempP->value;

                        //////////////////////////////////////////////////////////

                        if (tempP->parent == start)
                        {
                            if (start == startN->rootP)
                            {
                                if (tempP->rSon != NULL)
                                {
                                    tempP->rSon->parent = startN->rootP;
                                    startN->rootP->rSon = tempP->rSon;
                                }
                                else if (tempP->rSon == NULL)
                                {
                                    startN->rootP->rSon=NULL;
                                    start->rSon=NULL;                   ///////blaaaaaad
                                }
                            }

                            else if (tempP->rSon != NULL && tempP->lSon == NULL)
                            {
                                start->rSon = tempP->rSon;
                                tempP->rSon->parent=tempP->parent;   //zmiana
                            }

                            else if (tempP->rSon == NULL)
                            {
                                start->rSon = NULL;
                            }
                        }

                        else if (tempP->rSon == NULL)
                        {
                            tempP->parent->lSon = NULL;
                        }

                        else if (tempP->rSon != NULL)
                        {
                            tempP->rSon->parent = tempP->parent;
                            tempP->parent->lSon = tempP->rSon;
                        }

                        ////////////////////////////////////////////
                    }
                }
            }
        }
    }
}



//          SHOW        //

void in_order_page(struct Page *start)
{
    if (start->lSon != NULL)
        in_order_page(start->lSon);
    cout << start->value;
    cout << " ";

    if (start->rSon != NULL)
        in_order_page(start->rSon);
}



void in_order_tree_walk(struct Node *start)
{
    if (start->lSon != NULL)
        in_order_tree_walk(start->lSon);

    if (start->rootP != NULL) {
        cout << start->value << " ";
        in_order_page(start->rootP);
        cout << endl;
    }
    if (start->rSon != NULL)
        in_order_tree_walk(start->rSon);
}
void show_node(struct Node *start)
{
    cout << start->value << " ";
    in_order_page(start->rootP);
    cout << endl;
}



int main()
{
    string ety, pol;
    unsigned int ile, x, y;
    rootL = NULL;


    cin >> ile;
    for (unsigned int i = 0; i<ile; i++)
    {
        cin >> pol;
        if (pol == "I")
        {
            cin >> ety;
            struct Node *temp;
            temp = searchN(rootL, ety);
            if (temp == NULL)
            {
                struct Node *newNode = new Node;
                newNode->value = ety;
                newNode->lSon = NULL;
                newNode->rSon = NULL;
                newNode->parent = NULL;
                newNode->rootP = NULL;
                cin >> x;
                dodawaniePfor(x, newNode);
                dodawanieNEW(newNode);
            }
            else {
                cin >> x;
                dodawaniePfor(x, temp);
            }

        }


        else if (pol == "D")
        {
            unsigned int x,Pdele;
            cin >> ety;
            cin >> x;
            struct Node *tempN;
            tempN = searchN(rootL, ety);

                for (unsigned int i = 0; i<x; i++)
                {
                    cin >> Pdele;
                    struct Page *tempP;
                    if (tempN != NULL)
                    {
                        tempP = searchP(tempN->rootP, Pdele);
                        if (tempP != NULL){
                            delePage(tempN, tempP);
                        }
                    }
                }

            if(tempN!=NULL){
            if(tempN->rootP==NULL)
            {
                deleNode(tempN);
            }
            }

            else if (tempN != NULL)
            {
                if (tempN->rootP == NULL)
                    deleNode(tempN);
            }

        }


        else if (pol == "F")
        {
            cin >> ety;
            cin >> y;
            if (searchN(rootL, ety) != NULL)
            {
                if (searchP(searchN(rootL, ety)->rootP, y) != NULL)
                {
                    cout << "1" << endl;
                }
                else cout << "0" << endl;
            }
            else cout << "0" << endl;
        }

        else if (pol == "A")
        {
            cin >> ety;
            if (searchN(rootL, ety) != NULL)
                show_node(searchN(rootL, ety));
            else cout << "-1" << endl;
        }

        else if (pol == "P")
        {
            if (rootL != NULL)
                in_order_tree_walk(rootL);
        }
    }


    return 0;
}
