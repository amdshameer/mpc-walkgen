////////////////////////////////////////////////////////////////////////////////
///
///\file zebulon_jerk_minimization_objective.h
///\brief Implement the jerk minimization objective
///\author Lafaye Jory
///\author Barthelemy Sebastien
///
////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef MPC_WALKGEN_FUNCTION_ZEBULON_JERK_MINIMIZATION_OBJECTIVE_H
#define MPC_WALKGEN_FUNCTION_ZEBULON_JERK_MINIMIZATION_OBJECTIVE_H

#include <mpc-walkgen/type.h>
#include <mpc-walkgen/model/zebulon_base_model.h>
#include <mpc-walkgen/model/lip_model.h>

#ifdef _MSC_VER
# pragma warning( push )
// C4251: class needs to have DLL interface
# pragma warning( disable: 4251)
#endif

namespace MPCWalkgen
{
  template <typename Scalar>
  class JerkMinimizationObjective
  {
    TEMPLATE_TYPEDEF(Scalar)

  public:
    JerkMinimizationObjective(const LIPModel<Scalar>& lipModel, const BaseModel<Scalar>& baseModel);
    ~JerkMinimizationObjective();

    const VectorX& getGradient(const VectorX& x0);
    const MatrixX& getHessian();

    void computeConstantPart();

  private:
    const LIPModel<Scalar>& lipModel_;
    const BaseModel<Scalar>& baseModel_;

    VectorX function_;
    MatrixX gradient_;
    MatrixX hessian_;
  };

}

#ifdef _MSC_VER
# pragma warning( pop )
#endif

#endif
