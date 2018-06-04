/*Nicholas Rich
6/4/18
a program that creats a graph
 */
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

struct node {//used to hold the data of the node
  int color = -1;//black is 1 red is 0
  char* name;
  int index = -1;
  node* previous = NULL;
};

//prototypes
void print(int adj[20][20]);
void addEdge(node* nodes[20], int adj[20][20], char* name1, char* name2, int weight);
void addVertex(node* nodes[20], node* &newn, char* name);
void deleteEdge(node* nodes[20], int adj[20][20], char* name1, char* name2);
void deleteVertex(int adj[20][20], int index);

int main () {//main function
  bool working = true;//while working
  char* input = new char[16];//used to hold inputs
  node* nodes[20];//used to hold vertexs
  for (int i = 0; i < 20; i++) {//make sure the nodes are empty
    nodes[i] = NULL;
  }
  int adj[20][20];//used for adjacency matrix
  for (int i = 0; i < 20; i ++) {
    for (int j = 0 ; j < 20; j++) {
      adj[i][j] = 0;
    }
  }
  while (working == true) {//while working
    cout << "would you like to add, distance, delete, or quit?" << endl;//promt the user for an input
    cin.getline(input, 16);
    if (strcmp(input, "quit") == 0) {//quit
      working = false;
    }
    if (strcmp(input, "delete") == 0) {//if delete
      cout << "do you want to delete a vertex or an edge?" << endl;
      cin.getline(input,16) ;
      if (strcmp(input, "vertex") == 0) {//delete vertex
	cout << "what is the node you want to delete?" << endl;
	cin.getline(input,16);
	int index;
	for (int i = 0; i < 20; i++) {
	  if (nodes[i] != NULL && strcmp(nodes[i]->name, input) == 0) {
	    index = i;
	    delete nodes[i];
	    nodes[i] = NULL;
	  }
	}
	deleteVertex(adj, index);
      }
      else {//delete edge
	cout << "whats the name of the first node?" << endl;
	char* name1 = new char[16];
	char* name2 = new char[16];
	cin.getline(name1, 16);
	cout << "what is the name of the second node?" << endl;
	cin.getline(name2, 16);
	deleteEdge(nodes,adj,name1,name2);
	print(adj);
      }
    }				   
    if (strcmp(input, "add") == 0) {//add
      cout << "do you want to add a vertex or an edge?" << endl;
      cin.getline(input, 16);
      if (strcmp(input, "vertex") == 0) {//add a vertex	
	char* name = new char[16];
	node* newn = new node;
	cout << "what is the nodes name?" << endl;
	cin.getline(name, 16);
	addVertex(nodes, newn, name);
      }
      else {//add and edge
	cout << "what is the name of the first vertex" << endl;
	char* name1 = new char[16];
	char* name2 = new char[16];
	cin.getline(name1, 16);
	cout << "what is the name of the second vertex" << endl;
	cin.getline(name2, 16);
	cout << "what is the weight of the line?" << endl;
	int weight;
	cin >> weight;
	cin.get();
	addEdge(nodes, adj, name1, name2, weight);
	print(adj);
      }
    }
  }
  return 0;
}

void addEdge(node* nodes[20], int adj[20][20], char* name1, char* name2, int weight) {//used to add and edge to the adjacency matrix
  int indexA = 0;
  int indexB = 0;
  for (int i = 0; i < 20; i++) {
    if(nodes[i] != NULL && (*(nodes[i]->name)) == *name1) {
      indexA = i;
    }
    else if (nodes[i] != NULL && (*(nodes[i]->name)) == *name2) {
      indexB = i;
    }
  }
  adj[indexA][indexB] = weight;
  adj[indexB][indexA] = weight;
}

void deleteEdge(node* nodes[20], int adj[20][20], char* name1, char* name2) {//used to remove from the adjacency matrix
  int indexA = 0;
  int indexB = 0;
  for (int i = 0; i < 20; i++) {
    if (nodes[i] != NULL && (*(nodes[i]->name)) == *name1) {
      indexA = i;
    }
    else if (nodes[i] != NULL && (*(nodes[i]->name)) == *name2) {
      indexB = i;
    }
  }
  adj[indexA][indexB] = 0;
  adj[indexB][indexA] = 0;
}


void addVertex(node* nodes[20], node* &newn, char* name) {//adding to the nodes array
  newn->name = name;
  newn->color = 1;
  for (int i = 0; i < 20; i++) {
    if(nodes[i] == NULL) {
      nodes[i] = newn;
      newn->index = i;
      return;
    }
  }
}

void deleteVertex(int adj[20][20], int index) {//removing from the nodes array
  for (int i = 0; i < 20; i++) {
    if (adj[index][i] != -1) {
      adj[index][i] = -1;
      adj[i][index] = -1;
    }
  }
}

void print(int adj[20][20]) {//print out the adjacecny matix
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << adj[i][j] ;
    }
    cout << endl;
  }
}
