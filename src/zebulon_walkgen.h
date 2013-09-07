////////////////////////////////////////////////////////////////////////////////
///
///\file zebulon_walkgen.h
///\brief Main program for Zebulon
///\author Lafaye Jory
///\date 19/06/13
///
////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef MPC_WALKGEN_ZEBULON_WALKGEN_H
#define MPC_WALKGEN_ZEBULON_WALKGEN_H

#include "type.h"
#include "model/lip_model.h"
#include "model/zebulon_base_model.h"
#include "function/zebulon_base_velocity_tracking_objective.h"
#include "function/zebulon_base_position_tracking_objective.h"
#include "function/zebulon_jerk_minimization_objective.h"
#include "function/zebulon_tilt_minimization_objective.h"
#include "function/zebulon_cop_centering_objective.h"
#include "function/zebulon_com_centering_objective.h"
#include "function/zebulon_cop_constraint.h"
#include "function/zebulon_com_constraint.h"
#include "function/zebulon_base_motion_constraint.h"
#include "solver/qpoases_solver.h"

namespace MPCWalkgen
{
  class ZebulonWalkgen
  {
  public:
    ZebulonWalkgen();
    ~ZebulonWalkgen();

    void setNbSamples(int nbSamples);
    void setSamplingPeriod(Scalar samplingPeriod);

    void setGravity(const Vector3& gravity);
    void setBaseCopConvexPolygon(const ConvexPolygon& convexPolygon);
    void setBaseComConvexPolygon(const ConvexPolygon& convexPolygon);
    void setComBodyHeight(Scalar comHeight);
    void setComBaseHeight(Scalar comHeight);
    void setBodyMass(Scalar mass);
    void setBaseMass(Scalar mass);
    void setWheelToBaseDistance(Scalar dist);
    void setAngleWheelToBaseCom(Scalar angle);

    void setVelRefInWorldFrame(const VectorX& velRef);
    void setPosRefInWorldFrame(const VectorX& posRef);
    void setCopRefInLocalFrame(const VectorX& copRef);

    void setBaseVelLimit(Scalar limit);
    void setBaseAccLimit(Scalar limit);
    void setBaseJerkLimit(Scalar limit);

    void setBaseStateX(const VectorX& state);
    void setBaseStateY(const VectorX& state);
    void setBaseStateRoll(const VectorX& state);
    void setBaseStatePitch(const VectorX& state);
    void setComStateX(const VectorX& state);
    void setComStateY(const VectorX& state);

    void setWeightings(const Weighting& weighting);
    void setConfig(const Config& config);

    bool solve(Scalar feedBackPeriod);

    const VectorX& getBaseStateX();
    const VectorX& getBaseStateY();
    const VectorX& getComStateX();
    const VectorX& getComStateY();

  private:
    void computeConstantPart();

    void computeNormalizationFactor(MatrixX& Q, MatrixX& A);

  private:
    LIPModel lipModel_;
    BaseModel baseModel_;

    BaseVelocityTrackingObjective velTrackingObj_;
    BasePositionTrackingObjective posTrackingObj_;
    JerkMinimizationObjective jerkMinObj_;
    TiltMinimizationObjective tiltMinObj_;
    CopCenteringObjective copCenteringObj_;
    ComCenteringObjective comCenteringObj_;
    CopConstraint copConstraint_;
    ComConstraint comConstraint_;
    BaseMotionConstraint baseMotionConstraint_;

    QPOasesSolver qpoasesSolver_;

    Weighting weighting_;
    Config config_;

    VectorX dX_;
    VectorX X_;
    VectorX B_;

    QPMatrices qpMatrix_;

    Scalar invObjNormFactor_;
    Scalar invCtrNormFactor_;

  };
}

#endif //MPC_WALKGEN_ZEBULON_WALKGEN_H
