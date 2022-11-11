# Diagram:

|Feature| Desc | PinName |    |Power|    | PinName | Desc |Feature|
|-------|------|---------|----|-----|----|---------|------|-------|
|    i  |SCK   |  D13    | 13 |     | 12 |  D12    |MISO  |   ~   |
|       |Slide3|  +3V3   | -  |     | 11 |  D11    |MOSI  |   ~i  |
|       |Slide4|  AREF   | -  |     | 10 |  D10    |SS    |   ~i  |
|       |Slide5|  A0     | 14 |     | 9  |  D9     |Slide2|    i  |
|    i  |      |  A1     | 15 |     | 8  |  D8     |Slide1|       |
|       |      |  A2     | 16 |     | 7  |  D7     |Seat5 |       |
|       |Reset |  A3     | 17 |     | 6  |  D6     |Seat4 |   ~   |
|       |SDA   |  A4     | 18 |     | 5  |  D5     |Seat3 |   ~   |
|    i  |SCL   |  A5     | 19 |     | 4  |  D4     |Seat2 |       |
|       |      |  A6     | 20 |     | 3  |  D3     |Seat1 |   ~i  |
|    i  |      |  A7     | 21 |     | 2  |  D2     |Buzzer|   ~i  |
|       |      |  +5V    | -  |     | -  |  GND    |Power |       |
|       |      |  RESET  | -  |     | -  |  RESET  |      |       |
|       |      |  GND    | -  |     | 1  |  RX/1   |Serial|       |
|       |      |  VIN    | -  |     | 0  |  TX/0   |Serial|       |
2, 3, 9, 10, 11, 13, A1, A5, A7
