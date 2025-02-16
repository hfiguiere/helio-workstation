/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.

    This SoundFont implementation is based on SFZero,
    written by Steve Folta and extended by Leo Olivers and Cognitone,
    distributed under MIT license, see README.md for details.
*/

#pragma once

#include "SoundFontSound.h"

class SoundFont2Sound final : public SoundFontSound
{
public:

    explicit SoundFont2Sound(const File &file);
    ~SoundFont2Sound() override;

    void loadRegions() override;
    void loadSamples(AudioFormatManager &formatManager) override;

    int getNumPresets() const override;
    String getPresetName(int whichPreset) const override;
    void setSelectedPreset(int whichPreset) override;
    int getSelectedPreset() const override;

    WeakReference<SoundFontSample> getSampleFor(double sampleRate);

private:

    friend class SoundFont2Reader;
    void addPreset(UniquePointer<Preset> &&preset);

    OwnedArray<Preset> presets;

    FlatHashMap<int, UniquePointer<SoundFontSample>> samplesByRate;

    int selectedPreset = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundFont2Sound)
};
