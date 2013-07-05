#include <mpc-walkgen/zebulon_walkgen_abstract.h>
#include "zebulon_walkgen.h"

using namespace MPCWalkgen;

ZebulonWalkgenImpl::ZebulonWalkgenImpl()
:walkgen(NULL)
{
  walkgen = new ZebulonWalkgen();
}

ZebulonWalkgenImpl::~ZebulonWalkgenImpl()
{
  if (walkgen!=NULL)
  {
    delete walkgen;
  }
}

void ZebulonWalkgenImpl::setNbSamples(int nbSamples)
{
  walkgen->setNbSamples(nbSamples);
}

void ZebulonWalkgenImpl::setSamplingPeriod(Scalar samplingPeriod)
{
  walkgen->setSamplingPeriod(samplingPeriod);
}

void ZebulonWalkgenImpl::setGravity(const Vector3& gravity)
{
  walkgen->setGravity(gravity);
}

void ZebulonWalkgenImpl::setBaseHull(const std::vector<Vector3> p)
{
  walkgen->setBaseHull(Hull(p));
}

void ZebulonWalkgenImpl::setComBodyHeight(Scalar comHeight)
{
  walkgen->setComBodyHeight(comHeight);
}

void ZebulonWalkgenImpl::setComBaseHeight(Scalar comHeight)
{
  walkgen->setComBaseHeight(comHeight);
}

void ZebulonWalkgenImpl::setBodyMass(Scalar mass)
{
  walkgen->setBodyMass(mass);
}

void ZebulonWalkgenImpl::setBaseMass(Scalar mass)
{
  walkgen->setBaseMass(mass);
}

void ZebulonWalkgenImpl::setVelRefInWorldFrame(const VectorX& velRef)
{
  walkgen->setVelRefInWorldFrame(velRef);
}

void ZebulonWalkgenImpl::setPosRefInWorldFrame(const VectorX& posRef)
{
  walkgen->setPosRefInWorldFrame(posRef);
}
void ZebulonWalkgenImpl::setCopRefInLocalFrame(const VectorX& copRef)
{
  walkgen->setCopRefInLocalFrame(copRef);
}

void ZebulonWalkgenImpl::setBaseVelLimit(Scalar limit)
{
  walkgen->setBaseVelLimit(limit);
}

void ZebulonWalkgenImpl::setBaseAccLimit(Scalar limit)
{
  walkgen->setBaseAccLimit(limit);
}

void ZebulonWalkgenImpl::setBaseJerkLimit(Scalar limit)
{
  walkgen->setBaseJerkLimit(limit);
}

void ZebulonWalkgenImpl::setBaseStateX(const VectorX& state)
{
  walkgen->setBaseStateX(state);
}

void ZebulonWalkgenImpl::setBaseStateY(const VectorX& state)
{
  walkgen->setBaseStateY(state);
}

void ZebulonWalkgenImpl::setComStateX(const VectorX& state)
{
  walkgen->setComStateX(state);
}

void ZebulonWalkgenImpl::setComStateY(const VectorX& state)
{
  walkgen->setComStateY(state);
}

void ZebulonWalkgenImpl::setWeightings(const Weighting& weighting)
{
  walkgen->setWeightings(weighting);
}

void ZebulonWalkgenImpl::setConfig(const Config& config)
{
  walkgen->setConfig(config);
}

void ZebulonWalkgenImpl::solve(Scalar feedBackPeriod)
{
  walkgen->solve(feedBackPeriod);
}

const VectorX& ZebulonWalkgenImpl::getBaseStateX()
{
  return walkgen->getBaseStateX();
}

const VectorX& ZebulonWalkgenImpl::getBaseStateY()
{
  return walkgen->getBaseStateY();
}

const VectorX& ZebulonWalkgenImpl::getComStateX()
{
  return walkgen->getComStateX();
}

const VectorX& ZebulonWalkgenImpl::getComStateY()
{
  return walkgen->getComStateY();
}

