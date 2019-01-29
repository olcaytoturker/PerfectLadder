#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <queue>
#include <iterator>
#include "Node.h"



using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}




int main(int argc, char* argv[]) {

    if(argc!=3){

        cout<<"Run the code with the following command: ./project4 [input_file] [output_file]"<<endl;
        return 1;

    }
    ifstream infile(argv[1]);
    string line;
    vector<string> input;

    getline(infile, line);
    vector<string> word;
    split1(line, word);
    int M=stoi(word[0]);
    int N=stoi(word[1]);
    int graph[M+1][N+1];
    bool visited[1001][1001]={false};


    for(int i=0;i<M;i++){

        getline(infile, line);
        vector<string> words;

        split1(line, words);
        for(int j=0; j<N; j++){

            graph[i+1][j+1]=stoi(words[j]);

        }

    }

    getline(infile, line);
    getline(infile, line);
    vector<string> wordd;
    split1(line, wordd);
    int startX=stoi(wordd[0]);
    int startY=stoi(wordd[1]);
    int targetX=stoi(wordd[2]);
    int targetY=stoi(wordd[3]);


    priority_queue<Node*, vector<Node*>, Node::compareNode> dist;

    Node *a=new Node(startX, startY, 0);
    dist.push(a);


    while(!dist.empty()) {

        Node *n=dist.top();
        dist.pop();


        if(n->X==targetX && n->Y==targetY){
            ofstream myfile;
            myfile.open(argv[2]);
            myfile<<n->distTo;
            myfile.close();
            cout<<n->distTo<<endl;
            break;
        }

        if(n->Y+1 <=N && visited[n->X][n->Y+1]==0) {

                Node* n1=new Node(n->X, n->Y+1, max(n->distTo, abs(graph[n->X][n->Y+1]-graph[n->X][n->Y])));
                dist.push(n1);

        }

        if(n->X+1 <=M && visited[n->X+1][n->Y]==0) {

            Node* n2=new Node(n->X+1, n->Y, max(n->distTo, abs(graph[n->X+1][n->Y]-graph[n->X][n->Y])));
            dist.push(n2);
        }

        if(n->Y-1 > 0 && visited[n->X][n->Y-1]==0) {

            Node* n3=new Node(n->X, n->Y-1, max(n->distTo, abs(graph[n->X][n->Y-1]-graph[n->X][n->Y])));
            dist.push(n3);

        }

        if(n->X-1 > 0 && visited[n->X-1][n->Y]==0) {

            Node* n3=new Node(n->X-1, n->Y, max(n->distTo, abs(graph[n->X-1][n->Y]-graph[n->X][n->Y])));
            dist.push(n3);
        }


        visited[n->X][n->Y]=true;

    }



    return 0;
}