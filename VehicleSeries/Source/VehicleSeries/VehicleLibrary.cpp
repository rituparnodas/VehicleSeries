// ©devdastour All Right Reserved 2019-2021, Current Author = DevDas.


#include "VehicleLibrary.h"
#include "WheeledVehicleMovementComponent.h"
#include "PhysicalMaterials\PhysicalMaterial.h"

TArray<UPhysicalMaterial*> UVehicleLibrary::GetPhysicalMaterialsUnderTires(UWheeledVehicleMovementComponent* VehMovement)
{
	TArray<UPhysicalMaterial*> Mats;

	if (VehMovement)
	{
		for (UVehicleWheel* Wheel : VehMovement->Wheels)
		{
			Mats.Emplace(Wheel->GetContactSurfaceMaterial());
		}
	}
	return Mats;
}

float UVehicleLibrary::GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehMovement)
{
	if (VehMovement)
	{
		return VehMovement->GetMaxSpringForce();
	}

	return 0.0f;
}

bool UVehicleLibrary::CheckSlipThreshold(UWheeledVehicleMovementComponent* VehMovement, float LongSlipThresh, float LatSlipThresh)
{
	if (VehMovement)
	{
		float Long = FMath::Clamp<float>(LongSlipThresh, 0, 1);
		float Lat = FMath::Clamp<float>(LatSlipThresh, 0, 1);

		return VehMovement->CheckSlipThreshold(Long, Lat);

	}

	return false;
}
