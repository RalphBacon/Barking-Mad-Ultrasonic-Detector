Video sponsored by https://www.PCBWay.com  
PCB Prototype the Easy Way - Full feature custom PCB prototype service  
DAZZLING CHRISTMAS COUPONS December 5th through 25th 2018  
Wishing you a happy Christmas. Mysterious gifts will be given away to 10,000 lucky PCBWayers  
https://www.pcbway.com/activity/christmascoupons.aspx  

# See Video #128 at https://www.youtube.com/ralphbacon  
(Direct link to video: https://youtu.be/KJpfw9ysWQU)

Reinforce good behaviour with a bark detector and deterrent

So we're looking after Dougle (a dog) longer term right now. He's a cute little thing but does like to bark when people come to the door. To the point where you can't hold a conversation. It's the small dog syndrome, I guess.

So I was looking for a "command reinforcer" - that is, something that could reinforce the command STOP without me having to raise my voice (too much). Or even say it at all.

It seems ultrasonic devices are looked upon favourably as they cause no pain, no distress and the dog can quickly learn that the unpleasant noise is directly related to his barking. He is ultimately in control.

That's the plan, anyway. But we all know what happens to the best laid plans of dogs and Ralph...

Given that Dougle, the dog, is half a sandwich short of a picnic it might take a while. We shall see.

I'm using some electronic intelligence with this device, courtesy of an Arduino UNO (or Nano, in the final version) to detect the bark(s) and determine whether, and for how long, to switch on the ultrasonic oscillator. It's a work in progress but I do have high hopes that this might nudge him in the right direction.

Bark detection is via a microphone preamplifier feeding into a peak detector which then feeds into an analog port of the Arduino. The Arduino will then switch the 12 volt ultrasonic oscillator on and off via a MOSFET (eventually).

I'm tempted to include an LCD screen that displays messages so that we know what it's doing. Failing that it will be some coloured LEDs. Perhaps a stick of NeoPixels to display the bark intensity too...

I went through quite a few audio detection options so the links are all below.

LINKS     LINKS     LINKS     LINKS     LINKS     LINKS     LINKS     

MAX446 data sheet (microphone preamplifier)  
https://cdn-shop.adafruit.com/datasheets/MAX4465-MAX4469.pdf

The piezo tweeter in the handheld model (just a loudspeaker)  
https://www.diytrade.com/china/pd/3240500/Piezo_Tweeter_38mm_25KHz.html

Everything you might want to know about the LM386 Low Voltage Audio Power Amp  
http://www.ti.com/lit/ds/symlink/lm386.pdf

The KEMO ultrasonic generator that I'm using, has a built in loudspeaker and variable frequency  
https://www.kemo-electronic.de/en/Light-Sound/Ultrasonic/Modules/M048N-Ultrasonic-Generator.php

The KEMO ultrasonic "cannon" that I'm not using - good for getting foxes out of your garden though  
https://www.kemo-electronic.de/en/Light-Sound/Ultrasonic/Modules/M161-Ultrasonic-Power-Cannon.php

The clap switch that I eventually did not use - but an interesting kit nonetheless:  
https://www.banggood.com/Voice-Control-Clap-Switch-Kit-High-Sensitive-LED-Rhythm-Bistable-Switch-DIY-Kit-p-1169225.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3312

---

If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so :)

My channel and blog are here:  
------------------------------------------------------------------  
https://www.youtube.com/RalphBacon  
https://ralphbacon.blog  
------------------------------------------------------------------  
