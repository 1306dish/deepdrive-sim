

#pragma once

#include "CoreMinimal.h"
#include "Private/Simulation/Misc/PIDController.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDeepDriveAgentSpeedController, Log, All);

class ADeepDriveAgent;
class ADeepDriveSplineTrack;
class ADeepDriveRoute;

/**
 * 
 */

//UCLASS(Blueprintable)
class DeepDriveAgentSpeedController
{
public:

	DeepDriveAgentSpeedController(const FVector &pidThrottleParams, const FVector &pidBrakeParams);

	~DeepDriveAgentSpeedController();

	void initialize(ADeepDriveAgent &agent, ADeepDriveSplineTrack &track, float safetyDistanceFactor);

	void initialize(ADeepDriveAgent &agent, ADeepDriveRoute &route, float safetyDistanceFactor);

	void initialize(ADeepDriveAgent &agent);

	void setRoute(ADeepDriveRoute &route);

	float limitSpeedByTrack(float desiredSpeed, float speedBoost);

	//float limitSpeedByNextAgent(float desiredSpeed);

	void update(float dT, float desiredSpeed, float brake);

	void update(float dT, float desiredSpeed, float desiredDistance, float curDistance);

	void brake(float strength);

	void reset();

private:

	ADeepDriveAgent					*m_Agent = 0;
	ADeepDriveSplineTrack			*m_Track = 0;
	ADeepDriveRoute					*m_Route = 0;

	PIDController					m_ThrottlePIDCtrl;
	PIDController					m_BrakePIDCtrl;

	float							m_curThrottle = 0.0f;

	float							m_SafetyDistanceFactor = 1.0f;
	FVector2D						m_BrakingDistanceRange;

	float							m_BrakingDeceleration = 800.0f;

};
