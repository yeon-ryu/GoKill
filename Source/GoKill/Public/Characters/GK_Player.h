﻿#pragma once

#include "CoreMinimal.h"
#include "Characters/GK_CharacterBase.h"
#include "Missions/MissionHandler.h"
#include "GK_Player.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UCameraComponent;

UCLASS()
class GOKILL_API AGK_Player : public AGK_CharacterBase
{
	GENERATED_BODY()
	
public:
	AGK_Player();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Grab(const FInputActionValue& Value);
	void Select(const FInputActionValue& Value);
    void ReleaseSelect(const FInputActionValue& value);
    void SystemWindow(const FInputActionValue& value);

public: // Camera Settings
    UCameraComponent* GetPlayerCamera();
    FVector GetCameraLocation();
    void SetCameraRotation(FRotator CameraRotation_);

public: // 시스템 창
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Widget")
	class UWidgetComponent* MainComp;

    UPROPERTY()
	class UMainWidget* MainWidget;

    bool bSystemOpen = false;

    void SetSystemMissionList();

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

    // 모션 컨트롤러 등록
	UPROPERTY(VisibleAnywhere, Category = MotionController, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* LeftHand;

	UPROPERTY(VisibleAnywhere, Category = MotionController, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* RightHand;

	UPROPERTY(VisibleAnywhere, Category = MotionController, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* LeftHandSK;

	UPROPERTY(VisibleAnywhere, Category = MotionController, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* RightHandSK;

    UPROPERTY(VisibleAnywhere, Category = MotionController, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* RightAim;

	UPROPERTY(VisibleAnywhere, Category = Widget, meta = (AllowPrivateAccess = "true"))
	class UWidgetInteractionComponent* WidgetInteractionComp;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* GrabAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SelectAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SystemAction;

    MissionHandler missions;

private: // test
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* TestKill_Action;

    void TestKill(const FInputActionValue& Value);
};
