#ifndef QPOASES_H
#define QPOASES_H

#include <Eigen/Dense>
#include "mpc/optimizer/optimizer.h"

namespace mpc
{
	namespace optimizer
	{
	
		class QPOASES : public mpc::optimizer::Optimizer
		{
			public:
			// Constructor
			QPOASES(mpc::model::Model *model_ptr);

			//Destructor
			~QPOASES();

			/**
			 @brief Function to perform the manipulation of the model parameters to be ready for the qpOASES active set method solver.
			 @param MatrixXd &H_matrix				reference to a global variable that stores the matrix H of the optimization problem.
			 @param MatrixXd &F_matrix				reference to a global variable that stores the matrix H of the 
			 */
			virtual void setOptimizationParams(int n, int horizon, int p, double H_matrix[], double F_matrix[]);

		   /**
			 @brief Function to define the cost function associated to the MPC problem 
			 @param mpc::Model *model 			pointer to the process model class
			 @param int &nWSR 					number of working set recalculations
			 @param double *cputime 			pointer to the defined time to solve the optimization problem. If NULL, it provides on output the actual calculation time of the optimization problem. 
			 */
//			virtual void computeOpt(Eigen::MatrixXd &H_, Eigen::MatrixXd &F_, int &nWSR, double *cputime);

			private:

			mpc::model::Model *model_;
			
			//int &nWSR;	//number of working set recalculations

		}; // @class QPOASES

	} // @namespace optimizer

} // @namespace mpc

#endif
