#ifndef QPOASES_H
#define QPOASES_H

#include <mpc/optimizer/optimizer.h>
#include <ros/ros.h>

namespace mpc
{
	namespace optimizer
	{
	
		class QPOASES : public mpc::optimizer::Optimizer
		{
			public:
			// Constructor
			QPOASES(ros::NodeHandle node, mpc::model::Model *model_ptr);

			//Destructor
			~QPOASES();


		   /**
			 @brief Function to solve the optimization problem formulated in the MPC  
			 @param Eigen::VectorXd x_k 		state vector
			 @param Eigen::VectorXd x_ref		reference vector 
			 */
			virtual void computeMPC(Eigen::VectorXd x_k, Eigen::VectorXd x_ref);

			private:
			
			/** Pointer to a Model object **/
			mpc::model::Model *model_;
			
			/** Global variables that define the optimization problem **/
			int states_, inputs_, horizon_;
			
			/** Utility to perform ROS actions (subscribe from/publish to a topic, read the parameter server..) **/
			ros::NodeHandle n_;
			
			/** Arrays that store the weight matrices read from the configuration file **/
			double * qss;	
			double * pss;
			double * rss;

			/**  Number of constraints **/
			int nConst_;
	
			/** Number of variables ( = horizon_*inputs_) **/
			int nVar_;

			/** Constraint vectors**/
			double * lbA_, *ubA_;

			/** Bound vectors **/
			double * lb_, * ub_;

			/** Extended constraint vectors **/
			double * lbA_bar_, * ubA_bar_;

			/** Extended bound vectors **/
			double * lb_bar_, * ub_bar_;

			/** Extended constraint matrix **/
			double * G_bar_; 

			//int &nWSR;	//number of working set recalculations

		}; // @class QPOASES

	} // @namespace optimizer

} // @namespace mpc

#endif
