"""
    otmorris --- An OpenTURNS module
    ==================================

    Contents
    --------
      'otmorris' is a module for OpenTURNS

"""

import sys
if sys.platform.startswith('win'):
    # this ensures OT dll is loaded
    import openturns

from .otmorris import *

__version__ = '0.0'

