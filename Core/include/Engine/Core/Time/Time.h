#pragma once

#include "Engine/Core/CoreAPI.h"

namespace Engine::Core::Time
{
    class CORE_API Time
    {
    public:
        using TimeProvider = double(*)();

        static void SetProvider(TimeProvider provider);

        static double GetTime();
        static float GetDeltaTime();
    };
}