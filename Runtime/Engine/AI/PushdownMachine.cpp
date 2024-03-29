﻿#include "PushdownMachine.h"
#include "PushdownState.h"
using namespace NLS::Engine;

PushdownMachine::PushdownMachine()
{
    activeState = nullptr;
}

PushdownMachine::~PushdownMachine()
{
}

void PushdownMachine::Update()
{
    if (activeState)
    {
        PushdownState* newState = nullptr;
        PushdownState::PushdownResult result = activeState->PushdownUpdate(&newState);

        switch (result)
        {
        case PushdownState::PushdownResult::Pop:
            {
                activeState->OnSleep();
                stateStack.pop();
                if (stateStack.empty())
                {
                    activeState = nullptr; //??????
                }
                else
                {
                    activeState = stateStack.top();
                    activeState->OnAwake();
                }
            }
            break;
        case PushdownState::PushdownResult::Push:
            {
                activeState->OnSleep();
                stateStack.push(newState);
                newState->OnAwake();
            }
            break;
        }
    }
}