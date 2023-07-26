//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Urika Pye
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// Internal structure for tree node
struct Node {
    Bid bid;
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) :
            Node() {
        bid = aBid;
    }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    Node* deleteNode(Node* node, string bidId);
    Node* findNode(string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void PreOrder();
    void PostOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);

};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // FixMe (1): initialize housekeeping variables
    //root is equal to nullptr
  	root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
  // recurse from root deleting every node
  
}

/**
 * Traverse the tree in order
 BSTPrintInorder(node) {
  if (node is null)
      return                     

  BSTPrintInorder(node⇢left)   
  Print node                     
  BSTPrintInorder(node⇢right)  
}
 */
void BinarySearchTree::InOrder() {
    // FixMe (2): In order root
    // call inOrder fuction and pass root 
  	inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    // FixMe (3): Post order root
    // postOrder root
  	postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    // FixMe (4): Pre order root
    // preOrder root
  	preOrder(root);
}



/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    // FIXME (5) Implement inserting a bid into the tree
    // if root equal to null ptr
    addNode(new Node(), bid);
}

Node* BinarySearchTree::deleteNode(Node* node, string bidId) {

  // Returning node if equal to nullptr
  if (node == nullptr) {
      return node;
  }

  // traverse down the left side of the tree if bidId is less than current pointer
  if (bidId.compare(node->bid.bidId) < 0) {
      node->left = deleteNode(node->left, bidId);
  }

    // traverse down the right side of the tree if bidId is greater than current pointer
  else if (bidId.compare(node->bid.bidId) > 0) {
      node->right = deleteNode(node->right, bidId);
  }
  else {
      // When no child elements
      if (node->left == nullptr && node->right == nullptr) {
          delete node;
          node = nullptr;
      }
      // 
      else if (node->left != nullptr && node->right == nullptr) {
          Node* temp = node;
          node = node->left;
          delete temp;
      }
      // one child, right kid
      else if (node->left == nullptr && node->right != nullptr) {
          Node* temp = node;
          node = node->right;
          delete temp;
      }
      // two children
      else {
          Node* temp = node->right;
          while (temp->left != nullptr) {
              temp = temp->left;
          }
          node->bid = temp->bid;
          node->right = deleteNode(node->right, temp->bid.bidId);
      }
  }
  return node;

}

void BinarySearchTree::Remove(string bidId) {
    // FIXME (6) Implement removing a bid from the tree
    // remove node root bidID
  // Calling personally generated function because everything when researching required 2 parameters to be taken in. Unable to figure out how to work it with one parameter taken in.
  this->deleteNode(root, bidId);
}

void displayBid(Bid bid);

/**
 * Search for a bid
 */

/*
BSTSearch(tree, key) {
  cur = tree⇢root   
  while (cur is not null)
     if (key == cur⇢key)
        return cur // Found
     else if (key < cur⇢key)
        cur = cur⇢left
     else
        cur = cur⇢right
  return null // Not found
}
*/
Node* BinarySearchTree::findNode(string bidId) {
    Node* current = root;

  	while(current != nullptr)
    {
      if(bidId == current -> bid.bidId) {
        return current;
      }
      else if(bidId < current -> bid.bidId) {
        current = current -> left;
        continue;
      }
      else if(bidId > current -> bid.bidId) {
        current = current -> right;
        continue;
      }
      else {
        cout << "null";
      }
    }
    return nullptr;
}

Bid BinarySearchTree::Search(string bidId) {
    // FIXME (7) Implement searching the tree for a bid
    // set current node equal to root

    Node* node = findNode(bidId);
    Bid ret{};
    if (node) {
      ret = node->bid;
    }

    return ret;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* newNode, Bid bid) {
    
    newNode->bid = bid;

    if (root == nullptr) {
        // root is equal to new node bid
        root = newNode;
    }
    else {
        // add Node root and bid
        Node* currentNode = root;
    
        
        while(currentNode != nullptr) {
            // Sorted by bidId
            if(newNode -> bid.bidId < currentNode -> bid.bidId) {
                if(currentNode->left == nullptr) {
                    currentNode->left = newNode;
                    currentNode = nullptr;
                }
                else {
                    currentNode = currentNode->left;
                }
            }
            else {
                if (currentNode -> right == nullptr) {
                    currentNode -> right = newNode;
                    currentNode = nullptr;
                }
                else {
                    currentNode = currentNode -> right;
                }
            }
        }
    }
  
    // FIXME (8) Implement inserting a bid into the tree
  	// Node* newNode = new Node();
  	// newNode->bid = bid;
  	// if(node->bid.bidId > bid.bidId) {
   //    node->left = newNode;
   //    if(node->left == nullptr) {
   //      node->left = newNode;
   //    } else {
   //      addNode(node->left, bid);
   //    }
   //  }
  	
    // if node is larger then add to left
        // if no left node
            // this node becomes left
        // else recurse down the left node
    // else
        // if no right node
            // this node becomes right
        //else
            // recurse down the left node
}
void BinarySearchTree::inOrder(Node* node) {
    // FixMe (9): Pre order root
    //if node is not equal to null ptr
    //InOrder not left
    //output bidID, title, amount, fund
    //InOder right

  if(node == nullptr) {
    return;
  }

  else {
    inOrder(node->left);
    // std::cout << node->bid.bidId << node->bid.title << node->bid.amount << node->bid.fund << std::endl;
    inOrder(node->right);
    displayBid(node->bid);
  }
}

void BinarySearchTree::postOrder(Node* node) {
  // FixMe (10): Pre order root
  //if node is not equal to null ptr
  //postOrder left
  //postOrder right
  //output bidID, title, amount, fund

  if(node == nullptr) {
    return;
  }
  // Maybe if/else statement is needed for removal function
  else {
    postOrder(node->left);
  
    postOrder(node->right);
  // std::cout << node->bid.bidId << node->bid.title << node->bid.amount << node->bid.fund << std::endl;
    displayBid(node->bid);
  }
}

void BinarySearchTree::preOrder(Node* node) {
  // FixMe (11): Pre order root
  //if node is not equal to null ptr
  //output bidID, title, amount, fund
  //postOrder left
  //postOrder right      
  if(node == nullptr) {
    return;
  }
  // std::cout << node->bid.bidId << node->bid.title << node->bid.amount << node->bid.fund << std::endl;
  else {
    preOrder(node->left);
    preOrder(node->right);
    displayBid(node->bid);
  }
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(std::remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98223";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "CS 300 Binary Search Tree Assignment Student Files/eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98223";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;
    bst = new BinarySearchTree();
    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}