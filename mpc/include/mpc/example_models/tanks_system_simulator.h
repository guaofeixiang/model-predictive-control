#ifndef MPC_MODEL_TANKSSYSTEMSIM_H
#define MPC_MODEL_TANKSSYSTEMSIM_H

#include <mpc/model/model.h>
#include <mpc/model/simulator.h>

namespace mpc
{

    namespace example_models
    {

		/**< @Class Simulator
		 This class provides methods to simulate a given model
		 \f[ \dot{x}(t) = Ax(t) + Bu(t) \f]
		 \f[ y(t) = Cx(t) \f]
		 on a fixed prediction horizon interval \f$ [t_0, t_N] \f$ with initial value \f$ x(t_0, x_0) = x_0 \f$ and given control \f$ u(\cdot, x_0) \f$. That is, for a given class mpc::model::Model object and a given control \f$ u \f$ the simulator can solve the differential or difference equation forward in time.
		 @brief This class provides methods to simulate a given model of a process defined by a class mpc::model::Model object
		 */
		class TanksSystemSimulator : public mpc::model::Simulator
		{
		    public:
				/**
				 @brief Constructor
				 @param mpc::model::Model *model pointer to process model class
				 */
				TanksSystemSimulator();

				/**
				 @brief Destructor
				 */
				~TanksSystemSimulator() {};


				/**
				 @brief Function used to simulate the specified plant 
				 @param mpc::model::Model *model 	pointer to the process model class "Model"
				 */
				double* simulatePlant(double *state_vect, double input_vect, double samplingTime);


		    protected:


		    private:

				double param1_, param2_;
				double * state_vect_;

	  
		};  //@class TanksSystemSimulator

    }  //@namespace model

}  //@namespace mpc


#endif
