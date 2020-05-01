import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

path = '../cmake-build-debug/data.csv'
data = pd.read_csv(path, delimiter=',')
print(data)

data_X = data.columns.values.astype(np.float64)
print("X shape: {}, X max: {}, X mean: {}".format(data_X.shape, data_X.max(), data_X.mean()))

data_Y = data.to_numpy()
print("Y shape: {}, Y max: {}, Y mean: {}".format(data_Y.shape, data_Y.max(), data_Y.mean()))

# First set up the figure, the axis, and the plot element we want to animate
fig, ax = plt.subplots(figsize=(5, 4))  # figsize=(1, 1) = 72x72px, (19, 11) ~ 1366x768

ax.set_xlim((0, 10))
ax.set_ylim((0, 1))

line, = ax.plot([], [], lw=2, zorder=1)
sctr = ax.scatter([], [], color='red', s=15, zorder=3)
text = ax.text(6, 0.9, '', fontsize=15,
               bbox={'facecolor': 'white', 'alpha': 0.5, 'pad': 3})


# animation function. This is called sequentially
# avaliable writers:
# print(animation.writers.list())

def animate(i):
    line.set_data(data_X, data_Y[i])
    sctr.set_offsets(np.vstack((data_X, data_Y[i])).transpose())  # [ [x1, y1], [x2, y2], ... ]
    text.set_text("Step: {}".format(i))

    return sctr, line, text


# call the animator. blit=True means only re-draw the parts that have changed.
anim = animation.FuncAnimation(fig, animate,
                               frames=data_Y.shape[0], interval=50, blit=True)

Writer = animation.writers['ffmpeg']
writer = Writer(fps=30, metadata=dict(artist='Me'), bitrate=1800, extra_args=['-vcodec', 'libx264'])
anim.save('2d-animated.mp4', writer=writer)
