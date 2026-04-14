# Inertial acceleration of the vehicle mass center in body reference frame

Generally, the absolute acceleration of a particle $A$ in a moving
reference frame of center B is:

$$
\begin{equation*}
\vec{a}_A = \vec{a}_B + \vec{\alpha}\times\vec{r} +
\vec{\omega}\times(\vec{\omega}\times\vec{r})
+2\vec{\omega}\times\vec{v}_{rel} + \vec{a}_{rel}
\end{equation*}
$$

Choosing an earth centered reference frame with constant angular
velocity ($\vec{\omega}^E$) and no acceleration yield to the simpler
form

$$
\begin{equation*}
\vec{a}_{A_E} = \vec{\omega}^E_E\times(\vec{\omega}^E_E\times\vec{r}^E_E)
+2\vec{\omega}^E_E\times\vec{v}^{rel}_E + \vec{a}^{rel}_E
\end{equation*}
$$

where the subscript $E$ indicate that the vector are expressed in the
earth reference frame.

Transforming this vectorial notation to matrix notation and noting that
the angular velocity of $F_B$ relative to $F_E$ is
$\vec{\omega}^B - \vec{\omega}^E$ yield to:

$$
\begin{equation*}
\vec{a}_{A_E} = \tilde{\omega}^E_E\tilde{\omega}^E_E\vec{r}^E_E
+2\tilde{\omega}^E_E\vec{v}^{rel}_E + \vec{a}^{rel}_E
\end{equation*}
$$

We could now expressed this equation in term of component in the body
fixed reference frame.

$$
\begin{equation*}
\vec{a}_{A_B} = L_{BE}\vec{a}_{A_E} =
L_{BE}(\tilde{\omega}^E_E\tilde{\omega}^E_E\vec{r}^E_E
+2\tilde{\omega}^E_E\vec{v}^{rel}_E + \vec{a}^{rel}_E)
\end{equation*}
$$

$$
\begin{equation*}
= L_{BE}\tilde{\omega}^E_E\tilde{\omega}^E_E\vec{r}^E_E +
2L_{BE}\tilde{\omega}^E_E\vec{v}^{rel}_E + (\tilde{\omega}^B -
\tilde{\omega}^E)_B\vec{v}^{rel}_B + \vec{a}^{rel}_B
\end{equation*}
$$

We could then transform

$$
\begin{equation*}
L_{BE}\tilde{\omega}^E_E\vec{v}^{rel}_E = (L_{BE}\tilde{\omega}^E_E
L_{EB})(L_{BE}\vec{v}^{rel}_E) = \tilde{\omega}^E_B\vec{v}^{rel}_B
\end{equation*}
$$

and

$$
\begin{equation*}
L_{BE}\tilde{\omega}^E_E\tilde{\omega}^E_E\vec{r}^E_E =
(L_{BE}\tilde{\omega}^E_E L_{EB})(L_{BE}\tilde{\omega}^E_E
L_{EB})(L_{BE}\vec{r}^E_E) =
\tilde{\omega}^E_B\tilde{\omega}^E_B\vec{r}^E_B
\end{equation*}
$$

We now have

$$
\begin{equation*}
\vec{a}_{A_B} = \vec{a}^{rel}_B + (\tilde{\omega}^B -
\tilde{\omega}^E)_B\vec{v}^E_B +
\tilde{\omega}^E_B\tilde{\omega}^E_B\vec{r}^E_B +
2\tilde{\omega}^E_B\vec{v}^{rel}_B
\end{equation*}
$$

which simplify to

$$
\begin{equation*}
\vec{a}_{A_B} = \vec{a}^{rel}_B + (\tilde{\omega}^B +
\tilde{\omega}^E)_B\vec{v}^E_B +
\tilde{\omega}^E_B\tilde{\omega}^E_B\vec{r}^E_B
\end{equation*}
$$

Defining vector component in $F_B$

$$
\begin{equation*}
\vec{v}^E_B = \begin{bmatrix}u \\ v \\ w\end{bmatrix}
\end{equation*}
$$
$$
\begin{equation*}
\vec{\omega}^B_B = \begin{bmatrix}p \\ q \\ r\end{bmatrix}
\end{equation*}
$$
$$
\begin{equation*}
\vec{\omega}^E_B = \begin{bmatrix}p^E_B \\ q^E_B \\ r^E_B\end{bmatrix} =
L_{BV}\begin{pmatrix}\cos{\lambda} \\ 0 \\ -\sin{\lambda}\end{pmatrix}\omega^E
\end{equation*}
$$

and matrix notation of angular velocity

$$
\begin{equation*}
\tilde{\omega}^B_B =
\begin{bmatrix}0&-r&q \\ r&0&-p \\ q&p&0\end{bmatrix}
\end{equation*}
$$

$$
\begin{equation*}
\tilde{\omega}^E_B =
\begin{bmatrix}0&-r^E_B&q^E_B \\ r^E_B&0&-p^E_B \\ q^E_B&p^E_B&0\end{bmatrix}
\end{equation*}
$$

# Acceleration of vehicle mass center espressed in a spherical coordinate system relative to rotating earth

The spherical coordinate system is compose of the three vector
($\vec{e}_r$, $\vec{e}_\lambda$, $\vec{e}_\mu$), where $\vec{e}_r$ point
in the direction of the mass center of the vehicle, $\vec{e}_\lambda$
point in the north direction and is perpendicular to $\vec{e}_r$,
$\vec{e}_\mu$ point east and is perpendicular to both previous vectors.
We could also define the direction of $\vec{e}_r$ with two angle, $\mu$
is the angle between the equatorial projection of $\vec{e}_r$ and a
reference meridian on the earth. $\lambda$ is the angle between
$\vec{e}_r$ and the equator. We could then define the relative velocity
and acceleration of the point C relative to earth by:

$$
\begin{equation*}
\vec{v}_{rel} = \dot{r}\vec{e}_r+ r\dot{\mu}\cos{\lambda}\vec{e}_\mu+ r\dot{\lambda}\vec{e}_\lambda
\end{equation*}
$$

$$
\begin{align*}
\vec{a}_{rel} = & (\ddot{r} - r\dot{\lambda}^2 -
                  r\dot{\mu}^2\cos^2{\lambda})\vec{e}_r+\\ 
                &  ((2\dot{r}\dot{\mu} + r\ddot{\mu})\cos{\lambda} -
                  2r\dot{\mu}\dot{\lambda}\sin{\lambda})\vec{e}_\mu+\\
                &  (2\dot{r}\dot{\lambda} + r\ddot{\lambda} +
                  r\dot{\mu}^2\sin{\lambda}\cos{\lambda})\vec{e}_\lambda
\end{align*}
$$

We can now derive the inertial velocity and acceleration of C:

$$
\begin{align*}
\vec{v}_C & = \vec{v}_O + \vec{v}_{rel} + \vec{\omega}\times\vec{r}\\
          & = \dot{r}\vec{e}_r+ r\dot{\mu}\cos{\lambda}\vec{e}_\mu+
              r\dot{\lambda}\vec{e}_\lambda+ \omega\vec{k}\times r\vec{e}_r\\
          & = \dot{r}\vec{e}_r+ r\cos{\lambda}(\dot{\mu} + \omega)\vec{e}_\mu
              + r\dot{\lambda}\vec{e}_\lambda
\end{align*}
$$

$$
\begin{equation*}
\vec{a}_C = \vec{a}_O + \vec{\alpha}\times\vec{r} +
              \vec{\omega}\times(\vec{\omega}\times\vec{r})
              +2\vec{\omega}\times\vec{v}_{rel} + \vec{a}_{rel}
\end{equation*}
$$

Each term will be evaluate separatly:

$$
\begin{align*}
\vec{\omega}\times(\vec{\omega}\times\vec{r}) & =
      \omega\vec{k}\times(\omega\vec{k}\times r\vec{e}_r)\\
    & = \omega\vec{k}\times(\omega r\cos{\lambda}\vec{e}_\mu)\\
    & = \omega^2r\cos{\lambda}(-\cos{\lambda}\vec{e}_r+\sin{\lambda}\vec{e}_\lambda)\\
    & = -\omega^2r\cos^2{\lambda}\vec{e}_r+ \omega^2r\cos{\lambda}\sin{\lambda}\vec{e}_\lambda
\end{align*}
$$

$$
\begin{align*}
\vec{\omega}\times\vec{v}_{rel} & = \omega\vec{k}\times(\dot{r}\vec{e}_r+
    r\dot{\mu}\cos{\lambda}\vec{e}_\mu+ r\dot{\lambda}\vec{e}_\lambda)\\
 & = \omega\dot{r}\cos{\lambda}\vec{e}_\mu+ \omega
     r\dot{\mu}\cos{\lambda}(-\cos{\lambda}\vec{e}_r+ \sin{\lambda}\vec{e}_\lambda) +
     \omega r\dot{\lambda}(-\cos{\lambda})\vec{e}_\mu\\
 & = \omega\cos{\lambda}(\dot{r}-r\dot{\lambda})\vec{e}_\mu- \omega
 r\dot{\mu}\cos^2{\lambda}\vec{e}_r+ \omega r\dot{\mu}\cos{\lambda}\sin{\lambda}\vec{e}_\lambda
\end{align*}
$$

The inertial acceleration of C is then:

$$
\begin{align*}
\vec{a}_C = &   (\ddot{r} - r\dot{\lambda}^2 -
                r\dot{\mu}^2\cos^2{\lambda} - 2\omega
                r\dot{\mu}\cos^2{\lambda} - \omega^2r\cos^2{\lambda})\vec{e}_r\\ 
            & + ((2\dot{r}\dot{\mu} + r\ddot{\mu})\cos{\lambda} -
                2r\dot{\mu}\dot{\lambda}\sin{\lambda}
              + 2\omega\cos{\lambda}(\dot{r}-r\dot{\lambda})\vec{e}_\mu\\
            & + (2\dot{r}\dot{\lambda} + r\ddot{\lambda} +
                r\dot{\mu}^2\sin{\lambda}\cos{\lambda} +2\omega
                r\dot{\mu}\cos{\lambda}\sin{\lambda} +
                \omega^2r\cos{\lambda}\sin{\lambda})\vec{e}_\lambda
\end{align*}
$$

which simplify to: $$
\begin{equatio
\begin{align*}
\vec{a}_C = &   (\ddot{r} - r\dot{\lambda}^2 -
            r(\omega+\dot{\mu})^2\cos^2{\lambda})\vec{e}_r\\ 
            & + ((2\dot{r}\dot{\mu} + r\ddot{\mu})\cos{\lambda} -
                2r\dot{\mu}\dot{\lambda}\sin{\lambda}
              + 2\omega\cos{\lambda}(\dot{r}-r\dot{\lambda})\vec{e}_\mu\\
            & + (2\dot{r}\dot{\lambda} + r\ddot{\lambda} +
            r\sin{\lambda}\cos{\lambda}(\omega+\dot{\mu})^2)\vec{e}_\lambda
\end{align*}
$$

We must now project the inertial acceleration from this vehicled carried
frame to the bidy fixed frame with the conversion matrix based on the
euler angle which define the angular position of $F_B$ relative to
$F_V$.

$$
\begin{equation*}
L_{BV} = \begin{bmatrix} \cos{\theta}\cos{\psi}&
                         \cos{\theta}\sin{\psi}& -\sin{\theta}\\
                         \sin{\phi}\sin{\theta}\cos{\psi}-\cos{\phi}\sin{\psi}&
                         \sin{\phi}\sin{\theta}\sin{\psi}+\cos{\phi}\cos{\psi}&
                         \sin{\phi}\cos{\theta}\\
                         \cos{\phi}\sin{\theta}\cos{\psi}+\sin{\phi}\sin{\psi}&
                         \cos{\phi}\sin{\theta}\sin{\psi}-\sin{\phi}\cos{\psi}&
                         \cos{\phi}\cos{\theta}
         \end{bmatrix}
\end{equation*}
$$

$$
\begin{align*}
\vec{a}_{C_B} & = L_{BV}\vec{a}_C\\
              & = L_{BV}(\vec{\omega}\times(\vec{\omega}\times\vec{r})
                + 2\vec{\omega}\times\vec{v}_{rel} + \vec{a}_{rel})\\
              & = L_{BV}\begin{bmatrix}r\cos{\lambda}\sin{\lambda}\\ 0\\
                  -r\cos^2{\lambda}\end{bmatrix}\omega^2  +
                2\vec{\omega}^E_B\times\vec{v}_{rel_B} +
                \vec{a}_{rel_B} + (\vec{\omega}^B -
                \vec{\omega}^E)_B\times\vec{v}^E_B \\
              & =  L_{BV}\begin{bmatrix}r\cos{\lambda}\sin{\lambda}\\ 0\\
                  -r\cos^2{\lambda}\end{bmatrix}\omega^2  +
                \vec{a}_{rel_B} + (\vec{\omega}^B +
                \vec{\omega}^E)_B\times\vec{v}^E_B\\
              & = \begin{bmatrix}\dot{u} \\ \dot{v} \\ \dot{w}\end{bmatrix} + 
                  \begin{bmatrix}c_x \\ c_y \\ c_z\end{bmatrix} + 
                  \begin{bmatrix}(q + q^E_B)w - (r + r^E_B)v\\
                                 (r + r^E_B)u - (p + p^E_B)w\\
                                 (p + p^E_B)v - (q + q^E_B)u\end{bmatrix}
\end{align*}
$$

We will also use the moment equation:

$$
\begin{align*}
L & = I_x\dot{p} - (I_y - I_z)qr\\
M & = I_y\dot{q} - (I_z - I_x)rp\\
N & = I_z\dot{r} - (I_x - I_y)pq
\end{align*}
$$

# System of equation

## Independant variable

$$
\begin{align*}
(\phi, \theta, \psi)\quad & \text{Euler angle defining orientation of the
vehicle relative to $F_V$}\\
(u, v, w)\quad & \text{Velocity of the vehicle relative to earth}\\
(p, q, r)\quad & \text{Absolute angle rate}\\
(\lambda, \mu, R)\quad & \text{Position of the rocket relative to earth}\\
(p^E_B, q^E_B, r^E_B)\quad & \text{Earth angular velocity in body axis}\\
(P, Q, R) \quad & \text{Relative angular velocity of body relative ro $F_V$
expressed in $F_B$}
\end{align*}
$$

## List of equations

$$
\begin{equation*}
X - mg\sin{\theta} = m(\dot{u} + c_x + (q^E_B+q)w - (r^E_B+r)v)
\end{equation*}
$$
$$
\begin{equation*}
Y + mg\cos{\theta}\sin{\phi} = m(\dot{v} + c_y + (r^E_B+r)u - (p^E_B+p)w)
\end{equation*}
$$
$$
\begin{equation*}
Z + mg\cos{\theta}\cos{\phi} = m(\dot{w} + c_z + (p^E_B+pvw -
(q^E_B+q)u)
\end{equation*}
$$

$$
\begin{align*}
L & = I_x\dot{p} - (I_y - I_z)qr\\
M & = I_y\dot{q} - (I_z - I_x)rp\\
N & = I_z\dot{r} - (I_x - I_y)pq
\end{align*}
$$

$$
\begin{equation*}
\begin{bmatrix}\dot{\phi} \\ \dot{\theta} \\ \dot{\psi}\end{bmatrix} = 
  \begin{bmatrix}1&\sin{\phi}\tan{\theta}&\cos{\phi}\tan{\theta}\\
                 0&\cos{\phi}&-\sin{\phi}\\
                 0&\sin{\phi}\sec{\theta}&\cos{\phi}\sec{\theta}\end{bmatrix}
  \begin{bmatrix}P \\ Q \\ R\end{bmatrix}
\end{equation*}
$$

$$
\begin{equation*}
\begin{bmatrix}P \\ Q \\ R\end{bmatrix} =
  \begin{bmatrix}p \\ q \\ r\end{bmatrix} - 
  L_{BV}\begin{bmatrix}(\omega^E -
 \dot{\mu})\cos{\lambda} \\ -\dot{\lambda}\\
 -(\omega^E + \dot{\mu})\sin{\lambda}\end{bmatrix}
\end{equation*}
$$

$$
\begin{equation*}
\begin{bmatrix}r\dot{\lambda} \\ r\dot{\mu}\cos{\lambda} \\ \dot{r}
  \end{bmatrix} = L_{VB}\begin{bmatrix}u \\ v \\ w\end{bmatrix}
\end{equation*}
$$

$$
\begin{equation*}
\vec{\omega}^E_B = \begin{bmatrix}p^E_B \\ q^E_B \\ r^E_B\end{bmatrix} =
L_{BV}\begin{pmatrix}\cos{\lambda} \\ 0 \\ -\sin{\lambda}\end{pmatrix}\omega^E
\end{equation*}
$$

$$
\begin{equation*}
L_{VB} = \begin{bmatrix}\cos{\theta}\cos{\psi}&
             \sin{\phi}\sin{\theta}\cos{\psi} - \cos{\phi}\sin{\psi}&
             \cos{\phi}\sin{\theta}\cos{\psi} + \sin{\phi}\sin{\psi}\\
             \cos{\theta}\sin{\psi}&
             \sin{\phi}\sin{\theta}\sin{\psi} + \cos{\phi}\cos{\psi}&
             \cos{\phi}\sin{\theta}\sin{\psi} - \sin{\phi}\cos{\psi}\\
             -\sin{\theta}&
             \sin{\phi}\cos{\theta}&
             \cos{\phi}\cos{\theta}\end{bmatrix}
\end{equation*}
$$
