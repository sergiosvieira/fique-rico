#ifndef __NODE__
#define __NODE__

#include <cstdio>
#include <map>
#include "transfer-function.h"

using namespace std;

typedef enum {INPUT, HIDDEN, OUTPUT, NONE} NodeType;

/* Node */

class Node {
public:
	Node(int id);
	~Node();
	virtual void print_info();
	inline int get_id() { return id_; }
	double value;
protected:
	unsigned int id_;
	unsigned int inputs_;
	unsigned int outputs_;
	NodeType node_type_;
};

/* InputNode */

class OutputNode;

class InputNode: public Node {
public:
	InputNode(int id);
	void add_output_node(OutputNode *out, double weight);
	void print_info();
private:
	map<OutputNode*, double> output_nodes_;
};

/* OutputNode */

class OutputNode: public Node {
public:
	OutputNode(int id);
	void set_transfer_function(TransferFunction* transfer_function);
	void add_input_node(InputNode *in, double weight);
	void print_info();
	double get_total_weighted_input(); /* função de ativação */
	//double get_output();
	void update_weights(double error);
private:
	map<InputNode*, double> input_nodes_;
	double N; // taxa de aprendizagem
	//* transfer_function_; /* função de transferência */
};

/* HiddenNode */

class HiddenNode: public Node {
public:
	HiddenNode(int id);
};

#endif /* __NODE__ */
