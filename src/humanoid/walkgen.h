#ifndef WALKGENHUMANOID
#define WALKGENHUMANOID

////////////////////////////////////////////////////////////////////////////////
///
///\file	walkgen.h
///\brief	Main program of the MPC
///\author	Lafaye Jory
///\author      Keith François
///\author	Herdt Andrei
///\version	1.2
///\date	27/04/12
///
////////////////////////////////////////////////////////////////////////////////

#include <mpc-walkgen/walkgen-abstract-humanoid.h>
#include "types.h"

namespace MPCWalkgen{

  class Interpolation;
  class QPSolver;

  namespace Humanoid{

    class QPGenerator;
    class QPPreview;
    class RigidBodySystem;
    class OrientationsPreview;

    class Walkgen :
        public WalkgenAbstractHumanoid
    {

    public:
      Walkgen(::MPCWalkgen::QPSolverType solvertype);
      ~Walkgen();

      virtual void init(const RobotData &robotData, const MPCData &mpcData);

      virtual const MPCSolution &online(double time, bool previewBodiesNextState=true);

      /// \name Accessors and mutators
      /// \{
      void reference(double dx, double dy, double dyaw);
      void reference(Eigen::VectorXd dx, Eigen::VectorXd dy, Eigen::VectorXd dyaw);
      /// \}

    public:
      virtual const SupportState &currentSupportState() const;
      virtual inline void currentSupportState(const SupportState &newSupportState){
        newCurrentSupport_=newSupportState;
        isNewCurrentSupport_=true;
      }

      virtual const BodyState & bodyState(BodyType body)const;
      virtual void bodyState(BodyType body, const BodyState & state);
      /// \}


    private:
      MPCData generalData_;

      ::MPCWalkgen::QPSolver * solver_;
      QPGenerator * generator_;
      QPPreview * preview_;
      ::MPCWalkgen::Interpolation * interpolation_;
      RigidBodySystem * robot_;

      OrientationsPreview * orientPrw_;

      MPCSolution solution_;
      VelReference velRef_;
      /// \brief The new value of reference velocity, updated with in online method
      VelReference newVelRef_;
      QPPonderation ponderation_;
      /// \brief The new value of current support state, updated with in online method
      SupportState newCurrentSupport_;
      bool isNewCurrentSupport_;


      /// \brief Time at which the problem should be updated
      double upperTimeLimitToUpdate_;
      double upperTimeLimitToFeedback_;

      /// \brief Synchronised time with QP sampling
      double currentTime_;

    };
  }
}



#endif //WALKGENHUMANOID