#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

struct node {
  int color = -1;//black is 1 red is 0
  char* name;
  int index = -1;
  node* previous = NULL;
};

void print(int adj[20][20]);
void addEdge(node* nodes[20], int adj[20][20], char* name1, char* name2, int weight);
void addVertex(node* nodes[20], node* &newn, char* name);

int main () {
  bool working = true;
  char* input = new char[16];
  node* nodes[20];
  for (int i = 0; i < 20; i++) {
    nodes[i] = NULL;
  }
  int adj[20][20];
  for (int i = 0; i < 20; i ++) {
    for (int j = 0 ; j < 20; j++) {
      adj[i][j] = 0;
    }
  }
  while (working == true) {
    cout << "would you like to add, distance, delete, or quit?" << endl;
    cin.getline(input, 16);
    if (strcmp(input, "quit") == 0) {
      working = false;
    }
    if (strcmp(input, "add") == 0) {
      cout << "do you want to add a vertex or an edge?" << endl;
      cin.getline(input, 16);
      if (strcmp(input, "vertex") == 0) {	
	char* name = new char[16];
	node* newn = new node;
	cout << "what is the nodes name?" << endl;
	cin.getline(name, 16);
	addVertex(nodes, newn, name);
      }
      else {
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

void addEdge(node* nodes[20], int adj[20][20], char* name1, char* name2, int weight) {
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

void addVertex(node* nodes[20], node* &newn, char* name) {
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

void print(int adj[20][20]) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << adj[i][j] ;
    }
    cout << endl;
  }
}
