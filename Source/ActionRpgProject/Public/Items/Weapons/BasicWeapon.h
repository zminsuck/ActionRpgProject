#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicWeapon.generated.h"

class UBoxComponent;

UCLASS()
class ACTIONRPGPROJECT_API ABasicWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABasicWeapon();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UBoxComponent* WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};
