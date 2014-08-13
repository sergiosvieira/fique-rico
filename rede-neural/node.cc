#include "node.h"

/* Node */

Node::Node(int id) {
	id_ = id;
	node_type_ = NONE;
	inputs_ = 0;
	outputs_ = 0;
	value = 0.0;
}

Node::~Node() {
}

void Node::print_info() {
	printf("Node(%d)", id_);
	switch (node_type_) {
		case INPUT:
			printf(" - INPUT\n"); break;
		case HIDDEN:
			printf(" - HIDDEN\n"); break;
		case OUTPUT:
			printf(" - OUTPUT\n"); break;
		case NONE:
		default:
			break;
	}
	printf("-> Inputs: %d, Outputs: %d - Value: %.3f\n", inputs_, outputs_, value);
}

/* InputNode */

InputNode::InputNode(int id): Node(id) {
	node_type_ = INPUT;
	inputs_ = 1;
}

void InputNode::add_output_node(OutputNode *out, double weight) {
	//output_nodes_[out] = weight;
	output_nodes_.insert(std::make_pair(out, weight));
	outputs_++;
	out->add_input_node(this, weight);
}

void InputNode::print_info() {
	Node::print_info();
	for (map<OutputNode*, double>::iterator i = output_nodes_.begin(); i != output_nodes_.end(); i++) {
		printf("\tNode(%d) - w(%d,%d)=%.3f\n", (*i).first->get_id(), get_id(), (*i).first->get_id(), (*i).second);
	}
}

/* OutputNode */

OutputNode::OutputNode(int id): Node(id) {
	node_type_ = OUTPUT;
	outputs_ = 1;
	N = 1.0;
	//transfer_function_ = NULL;
}

/*
void OutputNode::set_transfer_function(TransferFunction* transfer_function) {
	transfer_function_ = transfer_function;
}
*/

void OutputNode::add_input_node(InputNode *in, double weight) {
	input_nodes_.insert(std::make_pair(in, weight));
	inputs_++;
}

void OutputNode::print_info() {
	Node::print_info();
	for (map<InputNode*, double>::iterator i = input_nodes_.begin(); i != input_nodes_.end(); i++) {
		printf("\tNode(%d) - w(%d,%d)=%.3f - input: %.3f\n", (*i).first->get_id(), get_id(), (*i).first->get_id(), (*i).second, (*i).first->value);
	}
}


double OutputNode::get_total_weighted_input() {
	double result = 0.0;
	double x, w;

	for (map<InputNode*, double>::iterator i = input_nodes_.begin(); i != input_nodes_.end(); i++) {
		x = (*i).first->value;
		w = (*i).second;
		result += (x * w);
	}

	return result;
}
/*
double OutputNode::get_output() {
	double result = 0.0;
	double value = get_total_weighted_input();

	if (transfer_function_ != NULL) {
		result = transfer_function_->get_result(value);
	}

	return result;
}
*/

void OutputNode::update_weights(double error) {
	double x, w;
	for (map<InputNode*, double>::iterator i = input_nodes_.begin(); i != input_nodes_.end(); i++) {
		x = (*i).first->value;
		w = (*i).second;
		// atualização dos pesos
		(*i).second = w + N * error * x;
	}
}

/* HiddenNode */

HiddenNode::HiddenNode(int id): Node(id) {
	node_type_ = HIDDEN;
}

