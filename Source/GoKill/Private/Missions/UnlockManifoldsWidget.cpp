﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Missions/UnlockManifoldsWidget.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "shDebug.h"
#include "Kismet/GameplayStatics.h"
#include "Missions/MissionHandler.h"

void UUnlockManifoldsWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 각 버튼 입력 이벤트에 대응하는 함수를 연결
    Btn1->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn1);
    Btn2->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn2);
    Btn3->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn3);
    Btn4->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn4);
    Btn5->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn5);
    Btn6->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn6);
    Btn7->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn7);
    Btn8->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn8);
    Btn9->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn9);
    Btn10->OnClicked.AddDynamic(this, &UUnlockManifoldsWidget::PressedBtn10);
}

void UUnlockManifoldsWidget::ResetBtn()
{
    // 버튼 누르기 성공 여부 초기화
    bSuccess = false;

    // pressedNum 초기화
    pressedNum.Empty();

    // btn 을 무작위로 배열
    //UKismetArrayLibrary::GenericArray_Shuffle(&btnNum, FArrayProperty);
    ShuffleTArray(btnNum);

    // btnText 에 해당 숫자를 입력
    BtnText1->SetText(FText::AsNumber(btnNum[0]));
    BtnText2->SetText(FText::AsNumber(btnNum[1]));
    BtnText3->SetText(FText::AsNumber(btnNum[2]));
    BtnText4->SetText(FText::AsNumber(btnNum[3]));
    BtnText5->SetText(FText::AsNumber(btnNum[4]));
    BtnText6->SetText(FText::AsNumber(btnNum[5]));
    BtnText7->SetText(FText::AsNumber(btnNum[6]));
    BtnText8->SetText(FText::AsNumber(btnNum[7]));
    BtnText9->SetText(FText::AsNumber(btnNum[8]));
    BtnText10->SetText(FText::AsNumber(btnNum[9]));
    PressedText->SetText(FText::FromString("Pressed Button"));
}

void UUnlockManifoldsWidget::CheckBtn()
{
    int now = pressedNum.Num();

    if (pressedNum[now - 1] != now) {
        // 미션 실패 처리 (에러음, 리셋)
        bError = true;
        Print("Mission Failed", FColor::Red);
        ResetBtn();
        return;
    }

    if (now == 10) {
        // 미션 성공 처리
        bSuccess = true;
        PressedText->SetText(FText::FromString("Success"));
    }
}

void UUnlockManifoldsWidget::ShuffleTArray(TArray<int32>& Array)
{
    // 현재 시간을 기반으로 시드 생성
    float CurrentTime = UGameplayStatics::GetRealTimeSeconds(nullptr);
    int32 Seed = FMath::FloorToInt(CurrentTime * 1000.0f); // 초 단위로 변환하여 정수로 변환

    // 무작위 시드 설정
    FMath::RandInit(Seed);

    int32 NumElements = Array.Num();

    for (int32 i = NumElements - 1; i > 0; --i)
    {
        // 0부터 i까지의 무작위 인덱스 선택
        int32 RandomIndex = FMath::RandRange(0, i);

        // 현재 요소와 무작위로 선택된 요소를 교환
        if (i != RandomIndex)
        {
            Array.Swap(i, RandomIndex);
        }
    }
}

void UUnlockManifoldsWidget::PressedBtn1()
{
    pressedNum.Add(btnNum[0]);
    PressedText->SetText(FText::AsNumber(btnNum[0]));
    int now = pressedNum.Num();
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn2()
{
    pressedNum.Add(btnNum[1]);
    PressedText->SetText(FText::AsNumber(btnNum[1]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn3()
{
    pressedNum.Add(btnNum[2]);
    PressedText->SetText(FText::AsNumber(btnNum[2]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn4()
{
    pressedNum.Add(btnNum[3]);
    PressedText->SetText(FText::AsNumber(btnNum[3]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn5()
{
    pressedNum.Add(btnNum[4]);
    PressedText->SetText(FText::AsNumber(btnNum[4]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn6()
{
    pressedNum.Add(btnNum[5]);
    PressedText->SetText(FText::AsNumber(btnNum[5]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn7()
{
    pressedNum.Add(btnNum[6]);
    PressedText->SetText(FText::AsNumber(btnNum[6]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn8()
{
    pressedNum.Add(btnNum[7]);
    PressedText->SetText(FText::AsNumber(btnNum[7]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn9()
{
    pressedNum.Add(btnNum[8]);
    PressedText->SetText(FText::AsNumber(btnNum[8]));
    CheckBtn();
}

void UUnlockManifoldsWidget::PressedBtn10()
{
    pressedNum.Add(btnNum[9]);
    PressedText->SetText(FText::AsNumber(btnNum[9]));
    CheckBtn();
}
