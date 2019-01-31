CXX := g++
CXXFLAGS := -std=c++11
srcfiles := PitchAddOrder.cpp PitchMessage.cpp PitchOrderCancel.cpp PitchOrderExecuted.cpp PitchTrade.cpp PitchManager.cpp main.cpp

pitcher: $(srcfiles)
	$(CXX) $(CXXFLAGS) $(srcfiles) -O3 -o pitcher

clean:
	rm -f pitcher
