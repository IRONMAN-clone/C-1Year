#include <iostream>
#include <conio.h>

#define K_UP 72
#define K_DN 80
#define K_Q  81

using namespace std;

typedef struct iact_msg_node
{
    int node_pos;
    char fill_with;
    char replace_with;
    string message;
    bool isMarked;
}Msg_Node;

void update_node(Msg_Node& node)
{
    if(node.isMarked)
    {
        node.message[node.node_pos] = node.fill_with;
        node.isMarked = false;
    }
    else if(!node.isMarked)
    {
        node.message[node.node_pos] = node.replace_with;
    }
}

int main(void)
{
    Msg_Node nodepool[]  =
    {
        {1, 'x', ' ', "[ ] Play", true},
        {1, 'x', ' ', "[ ] Quit", false},
        {1, 'x', ' ', "[ ] About", false}
    };
    
    int key = 0;
    int chc = 0;    

    system("cls");
    update_node(nodepool[0]);
    cout << nodepool[0].message << endl;
    cout << nodepool[1].message << endl;
    cout << nodepool[2].message << endl << endl;


    int pool_size = 3;

    while(key != K_Q)
    {
        char __key_Handler__ = getch();
        key =  __key_Handler__;

        if(key == K_UP){
            nodepool[chc].isMarked = false;
            update_node(nodepool[chc]);

            if(chc == 0){
                chc = pool_size - 1; 
            }
            else{
                --chc;
            }

            nodepool[chc].isMarked = true; 
            update_node(nodepool[chc]);
        }
        else if(key == K_DN)
        {
            nodepool[chc].isMarked = false;
            update_node(nodepool[chc]);

            if(chc == pool_size-1){
                chc = 0; 
            }
            else
            {
                ++chc;
            }

            nodepool[chc].isMarked = true; 
            update_node(nodepool[chc]);
        }

        system("cls");
        cout << nodepool[0].message << endl;
        cout << nodepool[1].message << endl;
        cout << nodepool[2].message << endl << endl;
    }

    return 0;
}