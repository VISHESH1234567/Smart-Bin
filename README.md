# Smart-Bin

### <pre> Problem Statement </pre>

Inefficient waste management practices in public areas lead to overflow, littering, and unsanitary conditions, affecting community well-being and the environment. This can be due to <b>carelessness of people</b> or due to <b>improper covering</b> of the bin. Additionally, densely populated areas like marketplaces may exacerbate the problem due to <b>insufficient availability of empty dustbins</b> to accommodate the generated waste. Furthermore, inadequate and <b>irregular emptying of dustbins</b> by Municipal Corporations can also contribute to the accumulation of waste and subsequent overflow. These problems are addressed by the <b> Smart Bin </b>

### <pre> Current Features of the Smart Bin</pre>

- **Automatic Lid Operation:** Lid opens and closes when someone brings the garbage near the lid.
- **Fill Percentage Monitoring:** Measures the height/percentage of garbage filled inside the bin.
- **Real-Time Data Management:** Updates fill data on cloud; alerts authorities if threshold exceeded.

### <pre> Future Advancements possible</pre>

- **Waste Compression:** Compresses soft waste to maximize space.
- **AI-based Garbage Detection:** Camera detects nearby garbage, raises alarms in case of improper disposal by any person.

### <pre> Implementation </pre>

- **2 Ultrasonic Sensors:** the sensor at the bottom of the lid measures percentage dustbin filled. The sensor on the wall detects if the person nearby is trying to open the bin to throw garbage.
- **Servo Motor:** Controls lid rotation for automatic opening and closing.
- **ESP8266 WiFi Module:** Enables wireless connectivity to upload the percent full along with the location of the dustbin to the cloud.
- **Arduino UNO:** Microcontroller platform, processes the program, compatible with a variety of sensors, acts as central part of the circuit by controliing several input and output pins.
- **Battery:** To power the Arduino circuit connection.
- **ThingSpeak API:** Cloud-based data management and allowing to send alert mails from the ThingSpeak account.

### <pre> Repository Structure </pre>

- `code` - code available for the final project code including fill level monitoring, automatic opening and closing of lid and uploading the data to the ThingSpeak cloud. Code for processing data on cloud and sending alert mails using ThingSpeak account is also available.
- `Report` - report containing in-depth analysis of the project, explaing working of the smart bin model and ThingSpeak channel.
- `demo` - contains the videos and images showing the circuit connections made and workings of the final model.

