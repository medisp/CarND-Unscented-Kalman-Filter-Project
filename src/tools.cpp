#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse = VectorXd(4);	
  rmse.fill(0);
  // Argument validity check:
  if (estimations.size() == 0 or estimations.size() != ground_truth.size() ) {
	cout << "Arguments are invalid, either missing or estimations and ground truth dont match" << endl; 
	return rmse;	
	}
	
  //calculating error
 for(int i=0; i<estimations.size(); i++) {
	VectorXd residual = estimations[i] - ground_truth[i];
	residual = residual.array()*residual.array();
	rmse += residual;
	}
 	
	//calculate the mean
  	// ... your code here
  rmse = rmse/ground_truth.size();
 	//calculate the squared root
	// ... your code here
  rmse = rmse.array().sqrt();
	// return the result
	return rmse;

}
