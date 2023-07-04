import os
import sys
sys.path.append(os.path.dirname(__file__))
# List imported names, but do not use pylint's --extension-pkg-allow-list option
# so that these names will be assumed present without having to compile and install.
# pylint: disable=no-name-in-module, import-error
from LinguaFrancafederate__server import (
    Tag, action_capsule_t, port_capsule, request_stop, schedule_copy, start
)
# pylint: disable=c-extension-no-member
import LinguaFrancafederate__server as lf
try:
    from LinguaFrancaBase.constants import BILLION, FOREVER, NEVER, instant_t, interval_t
    from LinguaFrancaBase.functions import (
        DAY, DAYS, HOUR, HOURS, MINUTE, MINUTES, MSEC, MSECS, NSEC, NSECS, SEC, SECS, USEC,
        USECS, WEEK, WEEKS
    )
    from LinguaFrancaBase.classes import Make
except ModuleNotFoundError:
    print("No module named 'LinguaFrancaBase'. "
          "Install using \"pip3 install LinguaFrancaBase\".")
    sys.exit(1)
import copy

# From the preamble, verbatim:
import time
import tracemalloc
tracemalloc.start()

# End of preamble.
# From the preamble, verbatim:
import time
import tracemalloc
tracemalloc.start()

# End of preamble.
# From the preamble, verbatim:
import time
import tracemalloc
tracemalloc.start()

# End of preamble.
# From the preamble, verbatim:
import time
import tracemalloc
tracemalloc.start()

# End of preamble.


# Python class for reactor _federate__server_main
class __federate__server_main:
    # Constructor
    def __init__(self, **kwargs):
        # Define parameters and their default values
        # Handle parameters that are set in instantiation
        self.__dict__.update(kwargs)
        # Define state variables
    
    @property
    def bank_index(self):
        return self._bank_index # pylint: disable=no-member
    
    

# Python class for reactor _serverreactor
class __serverreactor:
    # Constructor
    def __init__(self, **kwargs):
        # Define parameters and their default values
        # Handle parameters that are set in instantiation
        self.__dict__.update(kwargs)
        # Define state variables
        self.large_param = None
    
    @property
    def bank_index(self):
        return self._bank_index # pylint: disable=no-member
    
    
    def reaction_function_0(self, out_parameter):
        size_in_bytes = 3 * 1024 * 1024  # 3 MB
        self.large_param = bytes([0] * size_in_bytes)
        out_parameter.set(self.large_param)
        return 0
    def reaction_function_1(self, in_parameter, out_parameter):
        snapshot = tracemalloc.take_snapshot()
        top_stats = snapshot.statistics("lineno")
        
        print("[ Top 10 ]")
        for stat in top_stats[:10]:
            print(stat)
        
        time.sleep(2)
        param_temp = in_parameter.value
        out_parameter.set(param_temp)
        return 0



# Instantiate classes
federate__server_main_lf = [None] * 1
federate__server_server_lf = [None] * 1
# Start initializing federate__server of class _federate__server_main
for federate__server_main_i in range(1):
    bank_index = federate__server_main_i
    federate__server_main_lf[0] = __federate__server_main(
        _bank_index = 0,
    )
    # Start initializing federate__server.server of class _serverreactor
    for federate__server_server_i in range(1):
        bank_index = federate__server_server_i
        federate__server_server_lf[0] = __serverreactor(
            _bank_index = 0,
        )


# The main function
def main(argv):
    start(argv)

# As is customary in Python programs, the main() function
# should only be executed if the main module is active.
if __name__=="__main__":
    main(sys.argv)
