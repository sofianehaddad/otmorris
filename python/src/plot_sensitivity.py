"""
Plot Morris elementary effects

Examples
--------
>>> import openturns as ot

"""
import openturns as ot
import otmorris
import numpy as np
import matplotlib
import pylab as plt
import warnings

class PlotEE(object):
    """
    Plot elementary effects
    -----------------------

    The class perform the plot of sensitivity indices issued from Morris class.

    Parameters
    ----------
    morris: :class:`~otmorris.Morris`
        A Morris object.

    output_marginal: int
        Index of output marginal of interest.
        Default value is 0

    absolute_mean: bool
        Interest is mean of absolute elementary effects .
        Default value is True

    title: str
        Title for the graph

    """

    def __init__(self,
                 result,
                 output_marginal=0,
                 absolute_mean=True,
                 title="Elementary effects",
                 **kwargs):

        # set figure
        self._fig, self._ax = plt.subplots()

        # Here we suppose sensitivity_result is to be drawn
        if not hasattr(result, 'getClassName'):
            raise TypeError(" `result` should be an OpenTURNS type of class Morris ")
        # Work with result
        # Get input description / dim
        input_description = result.getInputDescription()
        dim = len(input_description)
        if absolute_mean:
            mean = result.getMeanAbsoluteElementaryEffects(output_marginal)
        else:
            mean = result.getMeanElementaryEffects(output_marginal)
        sigma = result.getStandardDeviationElementaryEffects(output_marginal)
        # Plot effects
        self._ax.scatter(mean, sigma, 'bo')
        # Annotate points
        for i, txt in enumerate(input_description):
            self.ax_.annotate(txt, (mean[i], sigma[i]))
        self._ax.set_ylabel('Elementary effects')
        self._ax.legend(loc=0)
        self._fig.suptitle(title, size = 14)

    def show(self, **kwargs):
        """
        Display the graph on screen.

        Parameters
        ----------
        kwargs:
            block: bool, optional
                If true (default), block until the graph is closed.

            These parameters are passed to matplotlib.pyplot.show()
        """
        self._fig.show(**kwargs)

    def save(self, fname, **kwargs):
        """
        Save the graph as file.

        Parameters
        ----------
        fname: bool, optional
            A string containing a path to a filename from which file format is deduced.

        kwargs:
            Refer to matplotlib.figure.Figure.savefig documentation for valid keyword arguments.
        """
        self._fig.savefig(fname, **kwargs)

    def getFigure(self):
        """
        Accessor to the underlying figure object.

        Refer to matplotlib.figure.Figure for further information.
        """
        return self._fig

    def getAxes(self):
        """
        Get the list of Axes objects.

        Refer to matplotlib.axes.Axes for further information.
        """
        return self._ax

    def close(self):
        """Close the figure."""
        plt.close(self._fig)
