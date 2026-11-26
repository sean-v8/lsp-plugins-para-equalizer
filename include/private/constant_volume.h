/*
 * Copyright (C) 2026 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2026 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-plugins-para-equalizer
 * Created on: 2 авг. 2021 г.
 *
 * lsp-plugins-para-equalizer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-plugins-para-equalizer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-plugins-para-equalizer. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef PRIVATE_PARA_EQUALIZER_CONSTANT_VOLUME_H_
#define PRIVATE_PARA_EQUALIZER_CONSTANT_VOLUME_H_

#include <cmath>
#include <lsp-plug.in/dsp-units/filters/Filter.h>
#include <lsp-plug.in/dsp-units/units.h>
#include <private/meta/para_equalizer.h>

namespace lsp
{
    namespace plugins
    {
        inline void decode_filter(uint32_t *ftype, uint32_t *slope, size_t mode)
        {
            #define EQF(x) meta::para_equalizer_metadata::EQF_ ## x
            #define EQS(k, t, ks) case meta::para_equalizer_metadata::EFM_ ## k:    \
                    *ftype = dspu::t; \
                    *slope = ks * *slope; \
                    return;
            #define EQDFL  default: \
                    *ftype = dspu::FLT_NONE; \
                    *slope = 1; \
                    return;

            switch (*ftype)
            {
                case EQF(BELL):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_BELL, 1)
                        EQS(RLC_MT, FLT_MT_RLC_BELL, 1)
                        EQS(BWC_BT, FLT_BT_BWC_BELL, 1)
                        EQS(BWC_MT, FLT_MT_BWC_BELL, 1)
                        EQS(LRX_BT, FLT_BT_LRX_BELL, 1)
                        EQS(LRX_MT, FLT_MT_LRX_BELL, 1)
                        EQS(APO_DR, FLT_DR_APO_PEAKING, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(HIPASS):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_HIPASS, 2)
                        EQS(RLC_MT, FLT_MT_RLC_HIPASS, 2)
                        EQS(BWC_BT, FLT_BT_BWC_HIPASS, 2)
                        EQS(BWC_MT, FLT_MT_BWC_HIPASS, 2)
                        EQS(LRX_BT, FLT_BT_LRX_HIPASS, 1)
                        EQS(LRX_MT, FLT_MT_LRX_HIPASS, 1)
                        EQS(APO_DR, FLT_DR_APO_HIPASS, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(HISHELF):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_HISHELF, 1)
                        EQS(RLC_MT, FLT_MT_RLC_HISHELF, 1)
                        EQS(BWC_BT, FLT_BT_BWC_HISHELF, 1)
                        EQS(BWC_MT, FLT_MT_BWC_HISHELF, 1)
                        EQS(LRX_BT, FLT_BT_LRX_HISHELF, 1)
                        EQS(LRX_MT, FLT_MT_LRX_HISHELF, 1)
                        EQS(APO_DR, FLT_DR_APO_HISHELF, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(LOPASS):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_LOPASS, 2)
                        EQS(RLC_MT, FLT_MT_RLC_LOPASS, 2)
                        EQS(BWC_BT, FLT_BT_BWC_LOPASS, 2)
                        EQS(BWC_MT, FLT_MT_BWC_LOPASS, 2)
                        EQS(LRX_BT, FLT_BT_LRX_LOPASS, 1)
                        EQS(LRX_MT, FLT_MT_LRX_LOPASS, 1)
                        EQS(APO_DR, FLT_DR_APO_LOPASS, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(LOSHELF):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_LOSHELF, 1)
                        EQS(RLC_MT, FLT_MT_RLC_LOSHELF, 1)
                        EQS(BWC_BT, FLT_BT_BWC_LOSHELF, 1)
                        EQS(BWC_MT, FLT_MT_BWC_LOSHELF, 1)
                        EQS(LRX_BT, FLT_BT_LRX_LOSHELF, 1)
                        EQS(LRX_MT, FLT_MT_LRX_LOSHELF, 1)
                        EQS(APO_DR, FLT_DR_APO_LOSHELF, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(NOTCH):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_NOTCH, 1)
                        EQS(RLC_MT, FLT_MT_RLC_NOTCH, 1)
                        EQS(BWC_BT, FLT_BT_RLC_NOTCH, 1)
                        EQS(BWC_MT, FLT_MT_RLC_NOTCH, 1)
                        EQS(LRX_BT, FLT_BT_RLC_NOTCH, 1)
                        EQS(LRX_MT, FLT_MT_RLC_NOTCH, 1)
                        EQS(APO_DR, FLT_DR_APO_NOTCH, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(ALLPASS):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_ALLPASS, 2)
                        EQS(RLC_MT, FLT_BT_RLC_ALLPASS, 2)
                        EQS(BWC_BT, FLT_BT_BWC_ALLPASS, 2)
                        EQS(BWC_MT, FLT_BT_BWC_ALLPASS, 2)
                        EQS(LRX_BT, FLT_BT_LRX_ALLPASS, 1)
                        EQS(LRX_MT, FLT_BT_LRX_ALLPASS, 1)
                        EQS(APO_DR, FLT_DR_APO_ALLPASS, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(RESONANCE):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_RESONANCE, 1)
                        EQS(RLC_MT, FLT_MT_RLC_RESONANCE, 1)
                        EQS(BWC_BT, FLT_BT_RLC_RESONANCE, 1)
                        EQS(BWC_MT, FLT_MT_RLC_RESONANCE, 1)
                        EQS(LRX_BT, FLT_BT_RLC_RESONANCE, 1)
                        EQS(LRX_MT, FLT_MT_RLC_RESONANCE, 1)
                        EQS(APO_DR, FLT_DR_APO_PEAKING, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(BANDPASS):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_BANDPASS, 1)
                        EQS(RLC_MT, FLT_MT_RLC_BANDPASS, 1)
                        EQS(BWC_BT, FLT_BT_BWC_BANDPASS, 1)
                        EQS(BWC_MT, FLT_MT_BWC_BANDPASS, 1)
                        EQS(LRX_BT, FLT_BT_LRX_BANDPASS, 1)
                        EQS(LRX_MT, FLT_MT_LRX_BANDPASS, 1)
                        EQS(APO_DR, FLT_DR_APO_BANDPASS, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(LADDERPASS):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_LADDERPASS, 1)
                        EQS(RLC_MT, FLT_MT_RLC_LADDERPASS, 1)
                        EQS(BWC_BT, FLT_BT_BWC_LADDERPASS, 1)
                        EQS(BWC_MT, FLT_MT_BWC_LADDERPASS, 1)
                        EQS(LRX_BT, FLT_BT_LRX_LADDERPASS, 1)
                        EQS(LRX_MT, FLT_MT_LRX_LADDERPASS, 1)
                        EQS(APO_DR, FLT_DR_APO_LADDERPASS, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(LADDERREJ):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_LADDERREJ, 1)
                        EQS(RLC_MT, FLT_MT_RLC_LADDERREJ, 1)
                        EQS(BWC_BT, FLT_BT_BWC_LADDERREJ, 1)
                        EQS(BWC_MT, FLT_MT_BWC_LADDERREJ, 1)
                        EQS(LRX_BT, FLT_BT_LRX_LADDERREJ, 1)
                        EQS(LRX_MT, FLT_MT_LRX_LADDERREJ, 1)
                        EQS(APO_DR, FLT_DR_APO_LADDERREJ, 1)
                        EQDFL
                    }
                    break;
                }

            #ifdef LSP_USE_EXPERIMENTAL
                case EQF(ALLPASS2):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_ALLPASS2, 1)
                        EQS(RLC_MT, FLT_BT_RLC_ALLPASS2, 1)
                        EQS(BWC_BT, FLT_BT_RLC_ALLPASS2, 1)
                        EQS(BWC_MT, FLT_BT_RLC_ALLPASS2, 1)
                        EQS(LRX_BT, FLT_BT_RLC_ALLPASS2, 1)
                        EQS(LRX_MT, FLT_BT_RLC_ALLPASS2, 1)
                        EQS(APO_DR, FLT_DR_APO_ALLPASS2, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(ENVELOPE):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_BT_RLC_ENVELOPE, 1)
                        EQS(RLC_MT, FLT_MT_RLC_ENVELOPE, 1)
                        EQS(BWC_BT, FLT_BT_RLC_ENVELOPE, 1)
                        EQS(BWC_MT, FLT_MT_RLC_ENVELOPE, 1)
                        EQS(LRX_BT, FLT_BT_RLC_ENVELOPE, 1)
                        EQS(LRX_MT, FLT_MT_RLC_ENVELOPE, 1)
                        EQS(APO_DR, FLT_MT_RLC_ENVELOPE, 1)
                        EQDFL
                    }
                    break;
                }

                case EQF(LUFS):
                {
                    switch (mode)
                    {
                        EQS(RLC_BT, FLT_A_WEIGHTED, 1)
                        EQS(RLC_MT, FLT_B_WEIGHTED, 1)
                        EQS(BWC_BT, FLT_C_WEIGHTED, 1)
                        EQS(BWC_MT, FLT_D_WEIGHTED, 1)
                        EQS(LRX_BT, FLT_K_WEIGHTED, 1)
                        EQS(LRX_MT, FLT_K_WEIGHTED, 1)
                        EQS(APO_DR, FLT_K_WEIGHTED, 1)
                        EQDFL
                    }
                    break;
                }
            #endif /* LSP_USE_EXPERIMENTAL */

                case EQF(OFF):
                    EQDFL;
            }
            #undef EQDFL
            #undef EQS
            #undef EQF
        }

        inline bool adjust_gain(size_t filter_type)
        {
            switch (filter_type)
            {
                case dspu::FLT_NONE:

                case dspu::FLT_BT_RLC_LOPASS:
                case dspu::FLT_MT_RLC_LOPASS:
                case dspu::FLT_BT_RLC_HIPASS:
                case dspu::FLT_MT_RLC_HIPASS:
                case dspu::FLT_BT_RLC_NOTCH:
                case dspu::FLT_MT_RLC_NOTCH:
                case dspu::FLT_BT_RLC_ALLPASS:
                case dspu::FLT_MT_RLC_ALLPASS:
                case dspu::FLT_BT_RLC_ALLPASS2:
                case dspu::FLT_MT_RLC_ALLPASS2:
                case dspu::FLT_BT_RLC_BANDPASS:
                case dspu::FLT_MT_RLC_BANDPASS:

                case dspu::FLT_BT_BWC_LOPASS:
                case dspu::FLT_MT_BWC_LOPASS:
                case dspu::FLT_BT_BWC_HIPASS:
                case dspu::FLT_MT_BWC_HIPASS:
                case dspu::FLT_BT_BWC_ALLPASS:
                case dspu::FLT_MT_BWC_ALLPASS:
                case dspu::FLT_BT_BWC_BANDPASS:
                case dspu::FLT_MT_BWC_BANDPASS:

                case dspu::FLT_BT_LRX_LOPASS:
                case dspu::FLT_MT_LRX_LOPASS:
                case dspu::FLT_BT_LRX_HIPASS:
                case dspu::FLT_MT_LRX_HIPASS:
                case dspu::FLT_BT_LRX_ALLPASS:
                case dspu::FLT_MT_LRX_ALLPASS:
                case dspu::FLT_BT_LRX_BANDPASS:
                case dspu::FLT_MT_LRX_BANDPASS:

                // Disable gain adjust for several APO filters, too
                case dspu::FLT_DR_APO_NOTCH:
                case dspu::FLT_DR_APO_LOPASS:
                case dspu::FLT_DR_APO_HIPASS:
                case dspu::FLT_DR_APO_ALLPASS:
                case dspu::FLT_DR_APO_ALLPASS2:
                case dspu::FLT_DR_APO_BANDPASS:
                    return false;
                default:
                    break;
            }
            return true;
        }

        inline bool filter_has_width(size_t type)
        {
            switch (type)
            {
                case dspu::FLT_BT_RLC_BANDPASS:
                case dspu::FLT_MT_RLC_BANDPASS:
                case dspu::FLT_BT_BWC_BANDPASS:
                case dspu::FLT_MT_BWC_BANDPASS:
                case dspu::FLT_BT_LRX_BANDPASS:
                case dspu::FLT_MT_LRX_BANDPASS:
                case dspu::FLT_BT_RLC_LADDERPASS:
                case dspu::FLT_MT_RLC_LADDERPASS:
                case dspu::FLT_BT_RLC_LADDERREJ:
                case dspu::FLT_MT_RLC_LADDERREJ:
                case dspu::FLT_BT_BWC_LADDERPASS:
                case dspu::FLT_MT_BWC_LADDERPASS:
                case dspu::FLT_BT_BWC_LADDERREJ:
                case dspu::FLT_MT_BWC_LADDERREJ:
                case dspu::FLT_BT_LRX_LADDERPASS:
                case dspu::FLT_MT_LRX_LADDERPASS:
                case dspu::FLT_BT_LRX_LADDERREJ:
                case dspu::FLT_MT_LRX_LADDERREJ:
                case dspu::FLT_DR_APO_LADDERPASS:
                case dspu::FLT_DR_APO_LADDERREJ:
                    return true;
            }

            return false;
        }

        constexpr float CONSTANT_VOLUME_OFF = -2000.0f;

        class PinkReference
        {
            static constexpr size_t POINTS = 512;
            static constexpr size_t RATE = 48000;
            dspu::Filter filter;
            float frequencies[POINTS];

        public:
            bool init()
            {
                for (size_t i = 0; i < POINTS; ++i)
                    frequencies[i] = 20.0 * std::pow(1000.0, (i + 0.5) / POINTS);
                return filter.init(NULL);
            }

            template <class Band, class Pitch>
            float level(size_t channels, size_t bands, Band band, Pitch pitch)
            {
                double total = 0.0;
                for (size_t channel = 0; channel < channels; ++channel)
                {
                    bool solo = false;
                    for (size_t i = 0; i < bands; ++i)
                        solo |= band(channel, i).pSolo->value() >= 0.5f;

                    const float shift = dspu::semitones_to_frequency_shift(pitch(channel));
                    double power[POINTS];
                    for (double &point : power)
                        point = 1.0;
                    for (size_t i = 0; i < bands; ++i)
                    {
                        const auto &b = band(channel, i);
                        if ((b.pMute->value() >= 0.5f) || (solo && (b.pSolo->value() < 0.5f)))
                            continue;

                        dspu::filter_params_t fp{};
                        fp.nType = b.pType->value();
                        fp.nSlope = b.pSlope->value() + 1;
                        decode_filter(&fp.nType, &fp.nSlope, b.pMode->value());
                        if (fp.nType == dspu::FLT_NONE)
                            continue;

                        const float center = b.pFreq->value() * shift;
                        const float width = filter_has_width(fp.nType)
                            ? std::exp2(0.5f * b.pWidth->value()) : 1.0f;
                        fp.fFreq = center / width;
                        fp.fFreq2 = center * width;
                        fp.fGain = adjust_gain(fp.nType) ? b.pGain->value() : 1.0f;
                        fp.fQuality = b.pQuality->value();

                        filter.update(RATE, &fp);
                        filter.rebuild();
                        float re[POINTS], im[POINTS];
                        filter.freq_chart(re, im, frequencies, POINTS);
                        for (size_t point = 0; point < POINTS; ++point)
                        {
                            const double r = re[point], q = im[point];
                            power[point] *= r * r + q * q;
                        }
                    }
                    for (const double point : power)
                        total += point;
                }

                const double mean = total / (POINTS * channels);
                if (!std::isfinite(mean))
                    return CONSTANT_VOLUME_OFF;
                return 10.0 * std::log10(lsp_max(mean, 1e-120));
            }
        };
    }
}
#endif
