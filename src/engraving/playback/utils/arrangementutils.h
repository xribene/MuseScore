/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MU_ENGRAVING_ARRANGEMENTUTILS_H
#define MU_ENGRAVING_ARRANGEMENTUTILS_H

#include "mpe/mpetypes.h"

#include "libmscore/score.h"
#include "libmscore/repeatlist.h"
#include "libmscore/tempo.h"
#include "types/constants.h"

namespace mu::engraving {
inline mpe::timestamp_t timestampFromTicks(const Score* score, const int tick)
{
    return score->repeatList().utick2utime(tick) * 1000;
}

inline mpe::duration_t durationFromTicks(const double beatsPerSecond, const int durationTicks, const int ticksPerBeat = Constants::division)
{
    float beatsNumber = static_cast<float>(durationTicks) / static_cast<float>(ticksPerBeat);

    return (beatsNumber / beatsPerSecond) * 1000;
}

static constexpr int CROTCHET_TICKS = Constants::division;
static constexpr int QUAVER_TICKS = Constants::division / 2;
static constexpr int SEMIQUAVER_TICKS = Constants::division / 4;
static constexpr int DEMISEMIQUAVER_TICKS = Constants::division / 8;

static constexpr double PRESTISSIMO_BPS_BOUND = 200 /*bpm*/ / 60.f /*secs*/;
static constexpr double PRESTO_BPS_BOUND = 168 /*bpm*/ / 60.f /*secs*/;
static constexpr double ALLEGRO_BPS_BOUND = 120 /*bpm*/ / 60.f /*secs*/;
static constexpr double MODERATO_BPS_BOUND = 108 /*bpm*/ / 60.f /*secs*/;
static constexpr double ANDANTE_BPS_BOUND = 76 /*bpm*/ / 60.f /*secs*/;
static constexpr double ADAGIO_BPS_BOUND = 66 /*bpm*/ / 60.f /*secs*/;
static constexpr double LENTO_BPS_BOUND = 40 /*bpm*/ / 60.f /*secs*/;
static constexpr double GRAVE_BPS_BOUND = 20 /*bpm*/ / 60.f /*secs*/;
}

#endif // MU_ENGRAVING_ARRANGEMENTUTILS_H
